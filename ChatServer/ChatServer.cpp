// ChatServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "LogicSystem.h"
#include <csignal>
#include <thread>
#include <mutex>
#include "AsioIOServicePool.h"
#include "CServer.h"
#include "ConfigMgr.h"
#include "RedisMgr.h"
#include "ChatServiceImpl.h"
//定时器模块，后续在acceptor绑定的iocontext线程执行定时回调清理超时时间
#include <boost/asio/steady_timer.hpp>
#include <chrono>

using namespace std;
bool bstop = false;
std::condition_variable cond_quit;
std::mutex mutex_quit;

int main()
{
	auto& cfg = ConfigMgr::Inst();
	auto server_name = cfg["SelfServer"]["Name"];
	try {
		auto pool = AsioIOServicePool::GetInstance();
		//将登录数设置为0
		RedisMgr::GetInstance()->HSet(LOGIN_COUNT, server_name,"0");

		//定义一个GrpcServer

		std::string server_address(cfg["SelfServer"]["Host"] + ":" + cfg["SelfServer"]["RPCPort"]);
		ChatServiceImpl service;
		grpc::ServerBuilder builder;
		// 监听端口和添加服务
		builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
		builder.RegisterService(&service);
		// 构建并启动gRPC服务器
		std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

		if (server.get() == nullptr) {
			std::cout << "grpc server is null!\n";
			return -1;
		}

		std::cout << "RPC Server listening on " << server_address << std::endl;

		//单独启动一个线程处理grpc服务
		std::thread  grpc_server_thread([&server]() {
				server->Wait();
			});

		boost::asio::io_context  io_context;
		boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
		signals.async_wait([&io_context, pool, &server](auto, auto) {
			io_context.stop();
			pool->Stop();
			server->Shutdown();
			});
		auto port_str = cfg["SelfServer"]["Port"];
		CServer s(io_context, atoi(port_str.c_str()));
		////中间是新增的定时器逻辑
		//boost::asio::deadline_timer timer(io_context);
		//std::function<void(const boost::system::error_code&)> timer_cb;
		//timer_cb = [&timer,&s,&timer_cb](const boost::system::error_code& ec) {
		//	//此时是主动cancel取消定时器，直接返回
		//	if (ec) {
		//		return;
		//	}
		//	//这里检查所有的连接，进行处理

		//	timer.expires_from_now(boost::posix_time::seconds(60));
		//	timer.async_wait(timer_cb);
		//};
		//// 第一次启动定时，注册第一轮等待
		//timer.expires_from_now(boost::posix_time::seconds(60));
		//timer.async_wait(timer_cb);
		///////
		io_context.run();
		RedisMgr::GetInstance()->HDel(LOGIN_COUNT, server_name);
		RedisMgr::GetInstance()->Close();
		grpc_server_thread.join();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << endl;
		RedisMgr::GetInstance()->HDel(LOGIN_COUNT, server_name);
		RedisMgr::GetInstance()->Close();
	}
	
}

