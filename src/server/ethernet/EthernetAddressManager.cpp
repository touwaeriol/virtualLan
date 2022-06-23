//
// Created by touwaerio on 2022/5/27.
//

#include <vl/core.h>

#include <utility>
#include <random>

#include <utility>

#include "ethernet/EthernetAddressManager.h"
#include "exception/AddressAlreadyInUseException.h"
#include "exception/AddressPoolFullException.h"


using namespace vl::core;
using namespace vl::server;


vl::server::EthernetAddressManager::EthernetAddressManager(
        const pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS> &ipRange,
        const pair<vl::core::IPV6_ADDRESS, vl::core::IPV6_ADDRESS> &ipv6Range) : _ipRange(ipRange),
                                                                                 _ipv6Range(ipv6Range),
                                                                                 _useIpv6(true) {
}

vl::server::EthernetAddressManager::EthernetAddressManager(
        const pair<std::string, std::string> &ipRange,
        const pair<std::string, std::string> &ipv6Range) : _useIpv6(true),
                                                           _ipRange(
                                                                   std::pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS>(
                                                                           ipStrToAddr(ipRange.first),
                                                                           ipStrToAddr(ipRange.second))),
                                                           _ipv6Range(
                                                                   std::pair<vl::core::IPV6_ADDRESS, vl::core::IPV6_ADDRESS>(
                                                                           (ipv6StrToAddr(ipv6Range.second)),
                                                                           ipv6StrToAddr(ipv6Range.second))) {

}

vl::server::EthernetAddressManager::EthernetAddressManager(
        pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS> ipRange) : _ipRange(ipRange), _useIpv6(false) {
}

vl::server::EthernetAddressManager::EthernetAddressManager(
        const pair<std::string, std::string> &ipRange) : _useIpv6(false), _ipRange(
        std::pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS>(
                ipStrToAddr(ipRange.first),
                ipStrToAddr(ipRange.second))) {
}

std::shared_ptr<Device> vl::server::EthernetAddressManager::allocDevice() {
    auto device = std::make_shared<Device>();
    device->set_ip(ipAddrToStr(allocIp()));
    device->set_mac(macAddrToStr(allocMac()));
    device->set_mtu(VL_TAP_MAX_MTU);
    device->set_ipnetmask(24);
    return device;
}

bool vl::server::EthernetAddressManager::macInUse(vl::core::MAC_ADDRESS addr) const {
    return _allocedMac.contains(addr);
}

MAC_ADDRESS vl::server::EthernetAddressManager::allocMac(vl::core::MAC_ADDRESS expect) {
    MAC_ADDRESS c;
    if (addressEquals<MAC_LEN>(expect, EMPTY_MAC)) {
        c = nextMac();
    } else {
        //手动分配
        if (macInUse(expect)) {
            throw AddressAlreadyInUseException(
                    std::string("mac地址已经在使用中: ") + reinterpret_cast<const char *>(&expect[0]));
        }
        c = expect;
    }
    //记录已经申请的mac地址
    this->_allocedMac.insert(c);
    return c;
}

bool EthernetAddressManager::ipInUse(vl::core::IPV4_ADDRESS addr) const {

    return this->_allocedIp.contains(addr);
}

IPV4_ADDRESS EthernetAddressManager::allocIp(vl::core::IPV4_ADDRESS expect) {
    IPV4_ADDRESS c;
    if (addressEquals<IPV4_LEN>(expect, EMPTY_IP)) {
        c = nextIp();
    } else {
        //手动分配
        if (ipInUse(expect)) {
            throw AddressAlreadyInUseException(
                    std::string("mac地址已经在使用中: ") + reinterpret_cast<const char *>(&expect[0]));
        }
        c = expect;
    }
    //记录已经申请的mac地址
    this->_allocedIp.insert(c);
    return c;
}

bool EthernetAddressManager::ipv6InUse(vl::core::IPV6_ADDRESS addr) const {

    return this->_allocedIpv6.contains(addr);
}

std::pair<bool, string> EthernetAddressManager::setDeviceUdpPort(MAC_ADDRESS mac, uint32_t port) {
    auto it = _macDeviceMap[mac];
    if (port == 0) {
        return {false, "错误的端口，端口必须大于0"};
    }
    if (it == nullptr) {
        it->set_publicudpport(port);
        return {true, ""};
    } else {
        return {false, "mac地址不存在"};
    }
}

/**
      * 根据mac地址获取信息
      * @param mac
      * @return
      */
std::optional<pair<IPV4_ADDRESS, uint32_t>> EthernetAddressManager::getDevicePublicAddr(MAC_ADDRESS mac) {

    auto device = _macDeviceMap[mac];
    if (device == nullptr) {
        return {};
    } else {
        return {pair<IPV4_ADDRESS, uint32_t>(ipStrToAddr(device->publicip()), device->publicudpport())};
    }
}

IPV6_ADDRESS EthernetAddressManager::allocIpv6(vl::core::IPV6_ADDRESS expect) {
    IPV6_ADDRESS c;
    if (addressEquals<IPV6_LEN>(expect, EMPTY_IPV6)) {
        do {
            for (int i = 0; i < IPV4_LEN; ++i) {
                uint32_t n1 = static_cast<uint32_t>(rand()), n2 = static_cast<uint32_t>( rand());
                memcpy(&n1, &c[0], 4);
                memcpy(&n2, &c[0] + 4, 2);
            }
        } while (!ipv6InUse(c));
    } else {
        //手动分配
        if (ipv6InUse(expect)) {
            throw AddressAlreadyInUseException(
                    std::string("mac地址已经在使用中: ") + reinterpret_cast<const char *>(&expect[0]));
        }
        c = expect;
    }
    //记录已经申请的mac地址
    this->_allocedIpv6.insert(c);
    return c;
}


/*static*/
IPV4_ADDRESS vl::server::EthernetAddressManager::ipStrToAddr(const std::string &add) {
    IPV4_ADDRESS r;
    auto sp = vl::core::split(add, ".");
    for (int i = 0; i < IPV4_LEN; i++) {
        r[i] = static_cast<unsigned char >(std::atoi(sp[i].c_str()));
    }
    return r;
}

/*static*/
std::string vl::server::EthernetAddressManager::ipAddrToStr(IPV4_ADDRESS add) {
    auto s1 = to_string(static_cast<uint32_t>(add[0]));
    auto s2 = to_string(static_cast<uint32_t>(add[1]));
    auto s3 = to_string(static_cast<uint32_t>(add[2]));
    auto s4 = to_string(static_cast<uint32_t>(add[3]));
    std::string r = std::string();
    r.resize(s1.size() + s2.size() + s3.size() + s4.size() + 3, '\0');
    int index = 0;
    memcpy(r.data() + index, s1.data(), s1.size());
    index += s1.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s2.data(), s2.size());
    index += s2.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s3.data(), s3.size());
    index += s3.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s4.data(), s4.size());
    return r;
}

/*static*/
IPV6_ADDRESS vl::server::EthernetAddressManager::ipv6StrToAddr(const std::string &add) {
    IPV6_ADDRESS r;
    auto sp = vl::core::split(add, ".");
    for (int i = 0; i < IPV6_LEN; i++) {
        r[i] = static_cast<unsigned char >( atoi(sp[i].c_str()));
    }
    return r;
}

/*static*/
std::string vl::server::EthernetAddressManager::ipv6AddrToStr(IPV6_ADDRESS add) {
    auto s1 = to_string(add[0]);
    auto s2 = to_string(add[1]);
    auto s3 = to_string(add[2]);
    auto s4 = to_string(add[3]);
    auto s5 = to_string(add[4]);
    auto s6 = to_string(add[5]);
    std::string r = std::string();
    r.resize(s1.size() + s2.size() + s3.size() + s4.size() + 5, '\0');
    int index = 0;
    memcpy(r.data() + index, s1.data(), s1.size());
    index += s1.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s2.data(), s2.size());
    index += s2.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s3.data(), s3.size());
    index += s3.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s3.data(), s3.size());
    index += s4.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s3.data(), s3.size());
    index += s5.size();
    *(r.data() + index) = '.';
    index += 1;
    memcpy(r.data() + index, s4.data(), s4.size());
    return r;
}


/*static*/
MAC_ADDRESS EthernetAddressManager::macStrToAddr(const std::string &add) {
    MAC_ADDRESS r;
    auto x = string("");
    auto sp = vl::core::split(add, ":");
    for (int i = 0; i < MAC_LEN; i++) {
        auto s = sp[i];
        if (s.size() > 1) {
            r[i] += strHexToByte(s[0]) * 16 + strHexToByte(s[1]);
        } else {
            r[i] += strHexToByte(s[0]);
        }
    }
    return r;
}

/*static*/
std::string EthernetAddressManager::macAddrToStr(MAC_ADDRESS add) {
    auto s1 = add[0];
    auto s2 = add[1];
    auto s3 = add[2];
    auto s4 = add[3];
    auto s5 = add[4];
    auto s6 = add[5];
    std::string r = std::string();
    r.resize(12 + 5, '\0');
    int index = 0;
    memcpy(r.data() + index, byteToStrHex(s1).data(), 2);
    index += 2;
    *(r.data() + index) = ':';
    index += 1;
    memcpy(r.data() + index, byteToStrHex(s2).data(), 2);
    index += 2;
    *(r.data() + index) = ':';
    index += 1;
    memcpy(r.data() + index, byteToStrHex(s3).data(), 2);
    index += 2;
    *(r.data() + index) = ':';
    index += 1;
    memcpy(r.data() + index, byteToStrHex(s4).data(), 2);
    index += 2;
    *(r.data() + index) = ':';
    index += 1;
    memcpy(r.data() + index, byteToStrHex(s5).data(), 2);
    index += 2;
    *(r.data() + index) = ':';
    index += 1;
    memcpy(r.data() + index, byteToStrHex(s6).data(), 2);
    return r;
}


IPV4_ADDRESS EthernetAddressManager::nextIp() const {
    auto s = _ipRange.first;
    auto e = _ipRange.second;
    IPV4_ADDRESS nIp;
    uint32_t offset = 0;
    do {
        if (nIp == e) {
            throw AddressPoolFullException("ipv4地址已经被分配完了，无法继续分配");
        }
        uint32_t next =
                (static_cast<uint32_t>(s[0]) << 24) + (static_cast<uint32_t>(s[1]) << 16) + (static_cast<uint32_t>(s[2])
                        << 8) + (static_cast<uint32_t>(s[3]) << 0) + offset;
        nIp[0] = static_cast<Byte> (next >> 24);
        nIp[1] = static_cast<Byte> (next >> 16);
        nIp[2] = static_cast<Byte> (next >> 8);
        nIp[3] = static_cast<Byte> (next >> 0);
        ++offset;
    } while (nIp[0] == 255 || nIp[1] == 255 || nIp[2] == 255 || nIp[3] == 255 || ipInUse(nIp));

    return nIp;
}

MAC_ADDRESS EthernetAddressManager::nextMac() const {
    MAC_ADDRESS r;
    do {
        std::random_device rand{};
        auto randInt = static_cast<uint32_t>(rand());
        // 第一个字节的最后一位必须是0 表示单播地址
        r[0] = static_cast<Byte>(randInt) & 0b11111110;
        r[1] = static_cast<Byte>(randInt >> 8);
        r[2] = static_cast<Byte>(randInt >> 16);
        r[3] = static_cast<Byte>(randInt >> 24);
        randInt = static_cast<uint32_t>(rand());
        r[4] = static_cast<Byte>(randInt);
        r[5] = static_cast<Byte>(randInt >> 8);
    } while (macInUse(r));
    return r;
}

/*static*/
/**
 * 0-f 转换成 0-16的数字
 * @param str
 * @return
 */
Byte EthernetAddressManager::strHexToByte(Byte str) {
    char *endptr;
    std::string s = to_string(str);
    /*非法字符会赋值给endptr*/
    long int i = strtol(s.c_str(), &endptr, 10);
    return static_cast<Byte>(i);
}

/**
 * 0-16 转换成0-f的字符
 * @param str
 * @return
 */
/*static*/
BYTE_ARRAY<2> EthernetAddressManager::byteToStrHex(Byte b) {
    char buf[10];
    sprintf(buf, "%x", b);
    std::string s(buf);
    if (s.length() > 1) {
        return BYTE_ARRAY<2>{s[0], s[1]};
    } else {
        return BYTE_ARRAY<2>{'0', s[0]};
    }
}






