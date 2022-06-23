//
// Created by touwaerio on 2022/5/18.
//


#include <vl/core.h>

#include "Client.h"
#include "test.hpp"


using namespace vl::client;
using namespace vl::core;

DEFINE_string(serverHost, "127.0.0.1", "主机地址");
DEFINE_int32(serverPort, 5200, "主机端口");
DEFINE_int32(udpPort, 5201, "本地的udp端口");
DEFINE_int64(tapDataQueueCap, 1024, "数据容量大小");
DEFINE_int64(udpDataQueueCap, 1024, "数据容量大小");
DEFINE_string(tapName,"vl-adapter0","设备名称");



GTEST_API_ int main(int argc, char **argv) {
    // 设置co日志输出;
    initLog();
    ::testing::InitGoogleTest(&argc, argv);//解析命令行中的GoogleTest参数，它允许用户通过多样的命令行参数来控制测试程序的行为（即定制命令行参数的行为）
    //运行测试
    auto code = RUN_ALL_TESTS();

    DLOG("初始化参数");
    std::string serverHost = FLAGS_serverHost;
    int serverPort = FLAGS_serverPort;
    int udpPort = FLAGS_udpPort;
    int tapDataQueueCap = FLAGS_tapDataQueueCap;
    int udpDataQueueCap = FLAGS_udpDataQueueCap;
    std::string tapName = FLAGS_tapName;

    DLOG("创建客户端");
    vl::client::Client client(serverHost, serverPort, udpPort, tapDataQueueCap ,udpDataQueueCap, tapName);

    client.init();
    auto r = client.start();
    assert(r.first);
    if (!r.first) {
        CLOG(std::string("启动客户端失败！！！ message = ") + r.second);
    }

    client.wait();


    return 0;
}


