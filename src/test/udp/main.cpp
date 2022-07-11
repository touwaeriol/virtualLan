//
// Created by touwaerio on 2022/7/2.
//

#include <vl/core.h>

#include <iostream>


int main(int argc, char **argv) {
    vl::core::initLog();

    auto server = std::thread([]() -> void {
        boost::asio::ip::udp::endpoint listen = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address("0.0.0.0"),
                                                                               5200);
        boost::asio::io_context context;

        boost::asio::ip::udp::socket sock(context);
        boost::system::error_code error;
        sock.open(boost::asio::ip::udp::v4(), error);
        if (error) {
            CLOG(fmt::format("打开sock失败 {}", error.message()));
        }
        sock.bind(listen, error);
        if (error) {
            CLOG(fmt::format("服务器绑定端口失败 {}", error.message()));
        }

        auto content = std::vector<Byte>();
        content.resize(1024);
        auto buf = boost::asio::buffer(content);
        auto peer = boost::asio::ip::udp::endpoint();

        while (true) {
            sock.wait(boost::asio::ip::udp::socket::wait_read, error);
            if (error) {
                CLOG(fmt::format("等待读取数据失败 {}", error.message()));
            }
            sock.receive_from(buf, peer, 0, error);
            if (error) {
                CLOG(fmt::format("读取数据失败 {}", error.message()));
            } else {
                DLOG(fmt::format("读取数据成功"));
            }

        }
    });

    auto client = std::thread([]() -> void {
        boost::asio::ip::udp::endpoint peer(boost::asio::ip::make_address("127.0.0.1"), 5200);
        boost::asio::io_context context;
        boost::asio::ip::udp::socket sock{context};

        boost::asio::ip::udp::endpoint listen{boost::asio::ip::make_address("0.0.0.0"), 5201};
        boost::system::error_code error;
        sock.open(boost::asio::ip::udp::v4(), error);
        if (error) {
            CLOG(fmt::format("客户端打开失败 {}", error.message()));
        }
        sock.bind(listen, error);
        if (error) {
            CLOG(fmt::format("客户端绑定失败 {}", error.message()));
        }
        std::vector<Byte> content{};
        content.resize(1024);
        auto buf = boost::asio::buffer(content);
        while (true) {
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
            sock.send_to(buf, peer, 0, error);
            if (error) {
                CLOG(fmt::format("发送数据失败 {}", error.message()));
            } else {
                DLOG(fmt::format("发送数据成功"))
            }
        }


    });


    server.join();
    client.join();


}


