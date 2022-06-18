//
// Created by touwaerio on 2022/6/18.
//

#ifndef VIRTUALLAN_ETHERDATA_H
#define VIRTUALLAN_ETHERDATA_H

#include <memory>
#include <co/all.h>
#include "util/typeDefile.h"
namespace vl::core {

    class EtherData;
}


namespace vl::core {


    class EtherData {

    public:

        std::vector<Byte> _data;

        sockaddr_in peer;

    };

}


#endif //VIRTUALLAN_ETHERDATA_H
