//
// Created by touwaerio on 2022/6/1.
//


#include "network/Tap.h"

vl::core::Tap::Tap() : _tap() {

}

vl::core::Tap::~Tap() {
    _tap.down();
}

std::string vl::core::Tap::name() const {

    return _tap.name();
}

void vl::core::Tap::name(const std::string &string) {
    _tap.name(string);
}

std::string vl::core::Tap::hwaddr() const {
    return _tap.hwaddr();
}

void vl::core::Tap::hwaddr(const std::string &string) {
    _tap.hwaddr(string);
}

int vl::core::Tap::mtu() const {
    return _tap.mtu();
}

void vl::core::Tap::mtu(int i) {
    _tap.mtu(i);
}

//t_tun vl::core::TapImpl::native_handle() const {
//    return _tap.native_handle();
//}

void vl::core::Tap::up() {
    return _tap.up();
}

void vl::core::Tap::down() {
    _tap.down();
}

std::string vl::core::Tap::ip() {
    return _ip;
}

void vl::core::Tap::ip(const std::string &ip, int netmask) {
    _ip = ip;
    _tap.ip(ip, netmask);
}

std::string vl::core::Tap::ipv6() {
    return _ipv6;
}

void vl::core::Tap::ipv6(const std::string &ipv6, int prefixLength) {
    _ipv6 = ipv6;
    _tap.ip(ipv6, prefixLength);
}


int vl::core::Tap::read(void *buf, size_t len) {
    return _tap.read(buf, len);
}

int vl::core::Tap::write(void *buf, size_t len) {
    return _tap.write(buf, len);
}

void vl::core::Tap::release() {
    _tap.release();
}

void vl::core::Tap::nonblocking(bool b) {
    _tap.nonblocking(b);
}


