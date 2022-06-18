//
// Created by touwaerio on 2022/5/23.
//

#include <stdint.h>
#include <co/byte_order.h>
#include <netinet/in.h>

#include "network/Frame.h"

namespace vl::core {


    /**
     * 判断第13 14 字节
     * 如果帧头跟随source mac地址的2 bytes的值大于等于1536 则此Frame为EthernetII格式的，如果小于1500则为Ethernet 802.3格式。
     * 接着比较紧接着的两bytes如果为0xFFFF则为Novell Ether 类型的Frame ;如果为0xAAAA则为Ethernet SNAP格式的Frame;如果都不是则为Ethernet 802.3/802.2格式的帧.
     * @tparam MTU
     * @param frame
     * @return
     */
    FrameType Frame::frameType(const vector <Byte> &content) {
        uint32_t length = ntoh16(*reinterpret_cast<uint16_t *> (&const_cast<vector <Byte> &>(content)[12]));
        if (length >= 1536) {
            return ETHERNET_V2;
        } else if (length < 1500) {
            uint32_t lldc = ntoh16(*reinterpret_cast<uint16_t *> (&const_cast<vector <Byte> &>(content)[14]));
            if (lldc == 0xFFFF) {
                return ETHERNET_NOVELL;
            } else if (lldc == 0xAAAA) {
                return ETHERNET_SNAP;
            } else {
                return ETHERNET_202_2;
            }
        } else {
            return UNKNOWN;
        }
    }



}