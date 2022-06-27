//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_NETBYTEORDER_CPP
#define VIRTUALLAN_NETBYTEORDER_H


#include <cstdint>
#include "util/typeDefile.h"


namespace vl::core {


    void byteReversal(Byte *ptr, std::size_t len);

    void ntoh(Byte *ptr, std::size_t len);

    void hton(Byte *ptr, std::size_t len);

    uint64_t ntoh64(uint64_t uint64);

    uint64_t hton64(uint64_t uint64);


    uint32_t ntoh32(uint32_t uint32);

    uint32_t hton32(uint32_t uint32);

    uint16_t ntoh16(uint16_t uint16);

    uint16_t hton16(uint16_t uint16);


}

#endif //VIRTUALLAN_NETBYTEORDER_CPP
