//
// Created by touwaerio on 2022/5/23.
//

#ifndef VIRTUALLAN_FRAME_H
#define VIRTUALLAN_FRAME_H

#include <vector>
#include <array>

#include "util/typeDefile.h"


namespace vl::core {
    class Frame;

    class EthernetV2Frame;
}


namespace vl::core {
    using namespace std;

    enum FrameType {
        ETHERNET_V2, // Ethernet II
        ETHERNET_202_2, // Ethernet Ethernet 802.3/202.2
        ETHERNET_NOVELL, // Ethernet Novell Ethernet
        ETHERNET_SNAP, // Ethernet SNAP
        UNKNOWN,//未知
    };


    class Frame {
        friend class EthernetV2Frame;

    public:
        virtual pair<const Byte *, size_t> src() = 0;

        virtual pair<const Byte *, size_t> dest() = 0;

        virtual array<Byte, 2> lengthOrType() = 0;

        virtual pair<const Byte *, size_t> data() = 0;

    public:
        static FrameType frameType(const vector<Byte> &content);



    };


}


#endif //VIRTUALLAN_FRAME_H
