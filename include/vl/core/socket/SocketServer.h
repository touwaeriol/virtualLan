//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_SOCKETSERVER_H
#define VIRTUALLAN_SOCKETSERVER_H

#include <co/co.h>
#include <memory>
#include <iostream>
#include <vector>

#include "util/Uncopymovable.hpp"
#include "exception/VlSocketException.h"

/**
 * 协程化的 socket 类，必须在co协程中运行！！
 */
namespace vl::core {
    class SocketServer;

    class SocketConnection;

}

namespace vl::core {
    class SocketServer : public Uncopymovable, public co::Closure {

    public:
        SocketServer(const std::string &bindIp, int bindPort, int bufSize);

        SocketServer(const sockaddr_in &bindAddress, int bufSize);

        ~SocketServer() override = default;

        void run() override = 0;

        virtual void onMessage(const sockaddr_in &peer, std::vector<char> buf, int len) = 0;

        virtual void onConnect(const sockaddr_in &peer) = 0;

        virtual void onClose(const sockaddr_in &peer) = 0;

        virtual void onException(const sockaddr_in &peer, vl::core::VlSocketException e) = 0;

        virtual void shutDown(int ms = 0) = 0;

        virtual void wait() = 0;

        virtual void operator()() {
            run();
        }


    protected:

        sockaddr_in _bindAddress;

        int _bufSize;

    };

}


#endif //VIRTUALLAN_SOCKETSERVER_H
