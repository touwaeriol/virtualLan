//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_ADDRESS_H
#define VIRTUALLAN_ADDRESS_H


#include <array>
#include <string.h>

#include "util/typeDefile.h"

#define IPV4_LEN 4
#define IPV6_LEN 16
#define MAC_LEN 6

#define EMPTY_IP vl::core::IPV4_ADDRESS{}
#define EMPTY_IPV6 vl::core::IPV6_ADDRESS{}
#define EMPTY_MAC vl::core::MAC_ADDRESS{}


using namespace std;


namespace vl::core {


    template<size_t LEN>
    class AddressHasher;

    template<typename T>
    class AddressEquals;

    template<typename T>
    bool addressEquals(const T &v1, const T &v2);

    template<int T> using BYTE_ARRAY = array<Byte, T>;

    typedef BYTE_ARRAY<IPV4_LEN> IPV4_ADDRESS;
    typedef BYTE_ARRAY<IPV6_LEN> IPV6_ADDRESS;
    typedef BYTE_ARRAY<MAC_LEN> MAC_ADDRESS;


    template<size_t LENGTH>
    class AddressHasher {
    public:
        size_t operator()(const BYTE_ARRAY<LENGTH> &bytes) const {
            size_t hash = 0;
            for (int i = 0; i < LENGTH; ++i) {
                hash = hash * 31 + bytes[i];
            }
            return hash;
        }
    };


    template<typename T>
    class AddressEquals{
    public:
        bool operator()(const T &v1, const T &v2) const{
            return addressEquals<T>(v1, v2);
        }
    };


    template<typename T>
    bool addressEquals(const T &v1, const T &v2) {
        return memcmp(&v1[0], &v2[0], v1.size()) == 0;
    }

}


#endif //VIRTUALLAN_ADDRESS_H
