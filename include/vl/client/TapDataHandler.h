//
// Created by touwaerio on 2022/6/11.
//

#ifndef VIRTUALLAN_TAPDATAHANDLER_H
#define VIRTUALLAN_TAPDATAHANDLER_H


#include <vl/core.h>

#include "Client.h"

namespace vl::client {
    class TapDataHandler;

}

namespace vl::client {
    using namespace vl::core;

    class TapDataHandler : public Uncopymovable {
        friend class Client;


    public:

        TapDataHandler(vl::client::Client &client, vector<Byte> &&data);

        TapDataHandler(TapDataHandler &&tapDataHandler);

        TapDataHandler(const TapDataHandler &tapDataHandler);

        TapDataHandler &operator=(const TapDataHandler &tapDataHandler) = delete;

        TapDataHandler &operator=(TapDataHandler &&tapDataHandler) = delete;


    public:

        void operator()();


    private:


    private:

        Client &_client;

        vector<Byte> _data;

    };

}


#endif //VIRTUALLAN_TAPDATAHANDLER_H
