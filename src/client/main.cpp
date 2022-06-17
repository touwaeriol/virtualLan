//
// Created by touwaerio on 2022/5/18.
//


#include <vl/core.h>

#include "Client.h"
#include "test.hpp"


using namespace vl::client;
using namespace vl::core;



DEF_main(argc, argv) {
    // 设置co日志输出;
    log::set_single_write_cb(console_log_writer);

    DLOG << "运行测试用例";
    unitest::run_all_tests();

    DLOG << "初始化参数";
    std::string serverHost = "127.0.0.1";
    int serverPort = 5200;
    int udpPort = 5201;
    int dataQueueCap = 1024;
    std::string tapName = "vl-adapter0";


    DLOG << "创建客户端";
    Client client(serverHost, serverPort, udpPort,1024,tapName);

    client.init();

    auto r = client.start();
    if (!r.first) {
        FLOG << "获取设备信息失败！！！ message = " + r.second;
    }

    client.wait();


    return 0;
}


