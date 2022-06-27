//
// Created by touwaerio on 2022/5/23.
//

#include <netinet/in.h>
#include "network/EthernetV2Frame.h"

using namespace std;


vl::core::EthernetV2Frame::EthernetV2Frame(const vector<Byte> &data) : _data(data) {}

vl::core::MAC_ADDRESS vl::core::EthernetV2Frame::src() {
    auto mac = MAC_ADDRESS();
    memcpy(mac.data(), &_data[6], MAC_LEN);
    return mac;
}

vl::core::MAC_ADDRESS vl::core::EthernetV2Frame::dest() {
    auto mac = MAC_ADDRESS();
    memcpy(mac.data(), &_data[0], MAC_LEN);
    return mac;
}

array<Byte, 2> vl::core::EthernetV2Frame::lengthOrType() {
    return {_data[12], _data[13]};
}

pair<const Byte *, size_t> vl::core::EthernetV2Frame::data() {
    return {&_data[14], _data.size() - 14};
}




