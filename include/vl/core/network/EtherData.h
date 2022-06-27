//
// Created by touwaerio on 2022/6/18.
//

#ifndef VIRTUALLAN_ETHERDATA_H
#define VIRTUALLAN_ETHERDATA_H

#include <memory>
#include <vector>
#include <boost/asio.hpp>

#include "util/typeDefile.h"


namespace vl::core {

    class EtherData;
}


namespace vl::core {


    class EtherData {

    public:

        std::vector<Byte> _content;

        boost::asio::ip::udp::endpoint _peer;

    };

}


#endif //VIRTUALLAN_ETHERDATA_H
