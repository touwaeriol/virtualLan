//
// Created by touwaerio on 2022/5/23.
//

#ifndef VIRTUALLAN_FRAME_H
#define VIRTUALLAN_FRAME_H

#include <array>

namespace vl::core {
    template<int MTU>
    class Frame;
}


namespace vl::core {
    enum FrameType {
        ETHERNET_V2, //Ethernet II
        ETHERNET_202_2, // Ethernet Ethernet 802.3/202.2
        ETHERNET_NOVELL, // Ethernet Novell Ethernet
        ETHERNET_SNAP, // Ethernet SNAP
        UNKNOWN,//未知
    };


    template<int MTU>
    class Frame {


    public:
        static FrameType frameType(const Frame<MTU> &&frame);

    public:
        virtual const char *src() = 0;

        virtual const char *dest() = 0;

        virtual uint8_t lengthOrType() = 0;

        virtual std::pair<const char *, uint8_t> data() = 0;

        virtual const char *fcs() = 0;

    protected:
        std::array<char, MTU> _content;

    };


}


#endif //VIRTUALLAN_FRAME_H
