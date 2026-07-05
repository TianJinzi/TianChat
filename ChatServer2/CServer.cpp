#include "CServer.h"
#include <iostream>
#include "AsioIOServicePool.h"
#include "UserMgr.h"
#include "RedisMgr.h"
#include "ConfigMgr.h"
CServer::CServer(boost::asio::io_context& io_context, short port):_io_context(io_context), _port(port),
_acceptor(io_context, tcp::endpoint(tcp::v4(),port)),_timer(io_context,std::chrono::seconds(60)),_b_stop(false)
{
	cout << "Server start success, listen on port : " << _port << endl;
	StartAccept();
}

CServer::~CServer() {
	cout << "Server destruct listen on port : " << _port << endl;
}

void CServer::HandleAccept(shared_ptr<CSession> new_session, const boost::system::error_code& error){
	if (_b_stop) {
		return;
	}
	if (error == boost::asio::error::operation_aborted) {
		return;
	}
	if (!error) {
		new_session->Start();
		lock_guard<mutex> lock(_mutex);
		_sessions.insert(make_pair(new_session->GetSessionId(), new_session));
	}
	else {
		cout << "session accept failed, error is " << error.what() << endl;
	}

	StartAccept();
}

void CServer::StartAccept() {
	auto &io_context = AsioIOServicePool::GetInstance()->GetIOService();
	shared_ptr<CSession> new_session = make_shared<CSession>(io_context, this);
	_acceptor.async_accept(new_session->GetSocket(), std::bind(&CServer::HandleAccept, this, new_session, placeholders::_1));
}

void CServer::ClearSession(std::string session_id) {
	
	lock_guard<mutex> lock(_mutex);
	if (_sessions.find(session_id) != _sessions.end()) {
		auto uid = _sessions[session_id]->GetUserId();

		//移除用户和session的关联
		UserMgr::GetInstance()->RmvUserSession(uid, session_id);
	}

	_sessions.erase(session_id);
	
}

shared_ptr<CSession> CServer::GetSession(std::string uuid) {
	auto it = _sessions.find(uuid);
	if (it != _sessions.end()) {
		return it->second;
	}
	return nullptr;
}

void CServer::on_timer(const boost::system::error_code& e) {
	if (e == boost::asio::error::operation_aborted) {
		return;
	}
	if (e) {
		std::cout << "timer error" << e.message() << std::endl;
		return;
	}
	std::vector<std::shared_ptr<CSession>>_expired_sessions;
	int session_count = 0;
	std::map<std::string, shared_ptr<CSession>>sessions_copy;
	{
		lock_guard<mutex>lock(_mutex);
		sessions_copy = _sessions;
	}
	time_t now = std::time(nullptr);
	for (auto iter = sessions_copy.begin();iter != sessions_copy.end();iter++) {
		auto b_expired = iter->second->IsHeartbeatExpired(now);
		if (b_expired) {
			iter->second->Close();
			_expired_sessions.push_back(iter->second);
			continue;
		}
		session_count++;
		
	}

	//设置session数量
	auto& cfg = ConfigMgr::Inst();
	auto self_name = cfg["SelfServer"]["Name"];
	auto count_str = std::to_string(session_count);
	RedisMgr::GetInstance()->HSet(LOGIN_COUNT, self_name, count_str);


	//处理过期session
	for (auto& session : _expired_sessions) {
		session->DealExceptionSession();
	}
	//再设置下一个60s检测
	_timer.expires_after(std::chrono::seconds(60));
	auto self = shared_from_this();
	_timer.async_wait([self](boost::system::error_code e) {
		self->on_timer(e);
		});
}

bool CServer::CheckValid(std::string session_id) {
	lock_guard<mutex>lock(_mutex);
	auto it = _sessions.find(session_id);
	if (it != _sessions.end()) {
		return true;
	}
	return false;
}

void CServer::StartTimer() {
	auto self = shared_from_this();
	_timer.async_wait([self](boost::system::error_code e) {
		self->on_timer(e);
		});
}

void CServer::Stop() {
	std::lock_guard<std::mutex> lock(_mutex);
	_b_stop = true;
	boost::system::error_code ec;

	_timer.cancel();
	_acceptor.cancel(ec);
	_acceptor.close(ec);

	for (auto se : _sessions) {
		se.second->Close();
	}
	_sessions.clear();
}
