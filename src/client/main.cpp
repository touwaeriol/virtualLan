//
// Created by touwaerio on 2022/5/18.
//


#include <vl/core.h>
#include <tuntap++.hh>

#include "test.hpp"
#include "Client.h"


using namespace vl::client;
using namespace vl::core;
using namespace tuntap;

void t_console_log_writer(const void *ptr, size_t len) {
    std::cout.write(static_cast<const char *>(ptr), len) << std::endl;

}

DEF_main(argc, argv) {
    // 设置co日志输出;
    log::set_single_write_cb(t_console_log_writer);

    DLOG << "运行测试用例";
    unitest::run_all_tests();


    DLOG << "初始化参数";
    std::string serverHost = "127.0.0.1";
    int serverPort = 8888;
    int clientPort = 8888;
    int mtu = 1476;
    std::string tapName = "vl-adapter0";


    DLOG << "创建客户端";
    Client client("localhost", 5200, 5200);
    client.init();

    auto r = client.start();
    if (!r.first) {
        ELOG << "获取设备信息失败！！！ message = " + r.second;
        return -1;
    }

    client.wait();
    return 0;
}

