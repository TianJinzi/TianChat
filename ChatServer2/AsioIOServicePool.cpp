#include "AsioIOServicePool.h"
#include <iostream>
using namespace std;

AsioIOServicePool::AsioIOServicePool(std::size_t size)
    : _ioServices(size), _works(size), _nextIOService(0)
{
    // 
    for (std::size_t i = 0; i < size; ++i) {
        _works[i] = std::make_unique<Work>(boost::asio::make_work_guard(_ioServices[i]));
    }

    // 遍历多个ioservice，创建多个线程，每个线程内部启动ioservice
    for (std::size_t i = 0; i < _ioServices.size(); ++i) {
        _threads.emplace_back([this, i]() {
            _ioServices[i].run();
            });
    }
}

AsioIOServicePool::~AsioIOServicePool()
{
    Stop();
    std::cout << "AsioIOServicePool destruct" << endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService()
{
    auto& service = _ioServices[_nextIOService++];
    if (_nextIOService == _ioServices.size()) {
        _nextIOService = 0;
    }
    return service;
}

void AsioIOServicePool::Stop()
{
    // 1. 直接停止所有 io_context（正确方式）
    for (auto& io : _ioServices) {
        io.stop();
    }

    // 2. 释放 work 守卫
    for (auto& work : _works) {
        work.reset();
    }

    // 3. 等待所有线程退出
    for (auto& t : _threads) {
        t.join();
    }
}