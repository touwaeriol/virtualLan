//
// Created by touwaerio on 2022/5/23.
//

#ifndef VIRTUALLAN_ETHERNETV2FRAME_H
#define VIRTUALLAN_ETHERNETV2FRAME_H

#include <cstdint>
#include <unordered_map>
#include <memory>
#include "Frame.h"


namespace vl::core {

    struct EthernetV2Frame;
}


namespace vl::core {
    using namespace std;


    enum EthernetV2Type {
        ARP = 0x0806,
        RARP = 0x8035,
        AARP = 0x80F34
    };


    struct EthernetV2Frame : public Frame {

    public:

        EthernetV2Frame(const vector<Byte> &data);


    public:

        MAC_ADDRESS src() override;

        MAC_ADDRESS dest() override;

        array<Byte, 2> lengthOrType() override;

        pair<const Byte *, size_t> data() override;

    private:

        const vector<Byte> &_data;


    };


}


#endif //VIRTUALLAN_ETHERNETV2FRAME_H
