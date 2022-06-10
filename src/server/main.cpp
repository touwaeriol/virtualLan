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


namespace test {

    DEF_test(alloc) {
        DEF_case(device)
        {
            vl::server::EthernetAddressManager e(std::pair<string, string>("192.168.101.1", "192.169.101.254"));
            const shared_ptr <Device> &device = e.allocDevice();
            std::cout << device->ip() << std::endl;
            std::cout << device->mac() << std::endl;
        }
    }
} // namespace test




DEF_main(argc, argv) {
//    log::set_single_write_cb(vl::core::console_log_writer);

    unitest::run_all_tests();


    vl::server::Server server{"0.0.0.0", 5200, pair<string, string>("192.168.100.1", "192.168.100.254"), 24};

    server.init();

    server.start();

    server.wait();

    return 0;

}


