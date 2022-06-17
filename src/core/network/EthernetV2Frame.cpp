//
// Created by touwaerio on 2022/5/23.
//

#include "network/EthernetV2Frame.h"

using namespace std;

vl::core::EthernetV2Frame::EthernetV2Frame(const vector <Byte> &data) : _data(data) {}

vl::core::EthernetV2Frame::EthernetV2Frame(vector <Byte> &&data) : _data(data) {}

pair<const Byte *, size_t> vl::core::EthernetV2Frame::src() {
    return {&_data[6], 6};
}

pair<const Byte *, size_t> vl::core::EthernetV2Frame::dest() {
    return {&_data[0], 0};
}

array<Byte, 2> vl::core::EthernetV2Frame::lengthOrType() {
    return {_data[12], _data[13]};
}

pair<const Byte *, size_t> vl::core::EthernetV2Frame::data() {
    return {nullptr, 0};
}



