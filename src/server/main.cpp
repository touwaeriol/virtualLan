//
// Created by touwaerio on 2022/5/18.
//

#include <grpcpp/grpcpp.h>
#include <vl/core.h>
#include <thread>

#include "service/RegisterServiceImpl.h"
#include "ethernet/EthernetAddressManager.h"
#include "Server.h"

using namespace vl::core;
using namespace vl::server;


int main(int argc, char **argv) {

    auto listenHost = "0.0.0.0";
    auto listenPort = 5200;
    auto ipRange = pair<string, string>("192.168.100.1", "192.168.100.254");
    auto netmask = 24;
    vl::server::Server server{listenHost, listenPort, ipRange, netmask};

    server.init();

    server.start();

    server.wait();


    return 0;

}


