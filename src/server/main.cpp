//
// Created by touwaerio on 2022/5/18.
//

#include <vl/core.h>
#include <thread>
#include "Server.h"


DEFINE_string(listenHost, "0.0.0.0", "监听host");
DEFINE_int32(listenPort, 5200, "监听端口");
DEFINE_string(ipRange, "192.168.100.1-192.168.100.254", "ip范围");
DEFINE_int32(netmask, 24, "子网掩码");


using namespace vl::core;
using namespace vl::server;


GTEST_API_ int main(int argc, char **argv) {
    // 初始化日志
    initLog();


    ::testing::InitGoogleTest(&argc, argv);//解析命令行中的GoogleTest参数，它允许用户通过多样的命令行参数来控制测试程序的行为（即定制命令行参数的行为）
//    ILOG("运行测试")
    auto code = RUN_ALL_TESTS();


    ILOG("解析命令行参数");

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    auto listenHost = FLAGS_listenHost;
    auto listenPort = FLAGS_listenPort;
    auto range = vl::core::split(FLAGS_ipRange, "-");
    auto ipRange = pair<string, string>(range[0], range[1]);
    auto netmask = FLAGS_netmask;
    vl::server::Server server(listenHost, listenPort, ipRange, netmask);


    server.init();

    server.start();

    server.wait();


    return 0;

}


