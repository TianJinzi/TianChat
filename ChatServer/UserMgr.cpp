#include "UserMgr.h"
#include "CSession.h"
#include "RedisMgr.h"
#include "ConfigMgr.h"

UserMgr:: ~ UserMgr(){
	_uid_to_session.clear();
}


std::shared_ptr<CSession> UserMgr::GetSession(int uid)
{
	std::lock_guard<std::mutex> lock(_session_mtx);
	auto iter = _uid_to_session.find(uid);
	if (iter == _uid_to_session.end()) {
		return nullptr;
	}

	return iter->second;
}

void UserMgr::SetUserSession(int uid, std::shared_ptr<CSession> session)
{
	std::lock_guard<std::mutex> lock(_session_mtx);
	_uid_to_session[uid] = session;
}

void UserMgr::RmvUserSession(int uid)
{ 
	auto uid_str = std::to_string(uid);
	//因为再次登录可能是其他服务器，所以会造成本服务器删除key，其他服务器注册key的情况
	// 有可能其他服务登录，本服删除key造成找不到key的情况
	auto& gCfgMgr = ConfigMgr::Inst();
	auto server_name = gCfgMgr["SelfServer"]["Name"];

	int result=RedisMgr::GetInstance()->DelIfMatch(USERIPPREFIX+uid_str, server_name);
	if (result == 1) {
		std::cout << "删除用户"<<uid<<"在redis的记录成功" << std::endl;
	}
	if (result == 0) {
		std::cout << "值不匹配未删除用户" << uid << std::endl;
	}
	if (result == -1) {
		std::cout << "发生错误，可能是脚本初始化错误" << std::endl;
	}

	{
		std::lock_guard<std::mutex> lock(_session_mtx);
		_uid_to_session.erase(uid);
	}

}

UserMgr::UserMgr()
{

}
