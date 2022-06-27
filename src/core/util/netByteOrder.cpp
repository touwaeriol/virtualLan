//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_NETBYTEORDER_CPP
#define VIRTUALLAN_NETBYTEORDER_CPP

#include <cstdint>
#include "util/netByteOrder.h"
#include "util/typeDefile.h"


namespace vl::core {

    void byteReversal(Byte *ptr, std::size_t len) {
        unsigned char m;
        for (int i = 0; i < len / 2; ++i) {
            m = ptr[len - 1 - i];
            ptr[len - 1 - i] = ptr[i];
            ptr[i] = m;
        }
    }

    void ntoh(Byte *ptr, std::size_t len) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        byteReversal(ptr, len);
#else
#error "无法识别的字节序";
#endif

    }

    void hton(Byte *ptr, std::size_t len) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        byteReversal(ptr, len);
#else
#error "无法识别的字节序";
#endif
    }

    uint64_t ntoh64(uint64_t uint64) {
        ntoh(reinterpret_cast<Byte *>(&uint64), sizeof(uint64_t));
        return uint64;
    }

    uint64_t hton64(uint64_t uint64) {
        hton(reinterpret_cast<Byte *>(&uint64), sizeof(uint64_t));
        return uint64;
    }

    uint32_t ntoh32(uint32_t uint32) {
        ntoh(reinterpret_cast<Byte *>(&uint32), sizeof(uint32_t));
        return uint32;
    }

    uint32_t hton32(uint32_t uint32) {
        hton(reinterpret_cast<Byte *>(&uint32), sizeof(uint32_t));
        return uint32;
    }


    uint16_t ntoh16(uint16_t uint16) {
        ntoh(reinterpret_cast<Byte *>(&uint16), sizeof(uint16_t));
        return uint16;
    }

    uint16_t hton16(uint16_t uint16) {
        hton(reinterpret_cast<Byte *>(&uint16), sizeof(uint16_t));
        return uint16;
    }


}

#endif //VIRTUALLAN_NETBYTEORDER_CPP
