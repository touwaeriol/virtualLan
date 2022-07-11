//
// Created by touwaerio on 2022/7/2.
//

#include <vl/core.h>

#include <iostream>

#include <yasio/yasio.hpp>

int main(int argc, char **argv) {

    auto t1 = std::thread([]() -> void {
        auto server = yasio::io_service(yasio::io_hostent("0.0.0.0", 5200));
        server.set_option()
        server.open(0, yasio::YCK_KCP_SERVER);
        server.start([](yasio::event_ptr &&event) -> void {
            switch(event->kind()){
                case yasio::YEK_ON_PACKET :{

                    break;
                }


                default:{

                    break;
                }
            }
        });


    });

    auto t2 = std::thread([]() -> void {

    });


    t1.join();
    t2.join();

}


