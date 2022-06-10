//
// Created by touwaerio on 2022/5/27.
//

#ifndef VIRTUALLAN_ETHERNETADDRESSMANAGER_H
#define VIRTUALLAN_ETHERNETADDRESSMANAGER_H

#include <vl/core.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>


namespace vl::server {
    class EthernetAddressManager;
}


namespace vl::server {
    using namespace vl::core;

    /**
     * 网络地址管理器，一个分组一个管理器
     */
    class EthernetAddressManager : public vl::core::Uncopymovable {


    public:
        EthernetAddressManager(pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS> ipRange,
                               pair<vl::core::IPV6_ADDRESS, vl::core::IPV6_ADDRESS> ipv6Range);


        EthernetAddressManager(pair<std::string, std::string> ipRange,
                               pair<std::string, std::string> ipv6Range
        );

        EthernetAddressManager(pair<vl::core::IPV4_ADDRESS, vl::core::IPV4_ADDRESS> ipRange);


        EthernetAddressManager(pair<std::string, std::string> ipRange);

        ~EthernetAddressManager() override = default;

    public:
        std::shared_ptr<Device> allocDevice();


        bool macInUse(vl::core::MAC_ADDRESS addr) const;


        bool ipInUse(vl::core::IPV4_ADDRESS addr) const;


        bool ipv6InUse(vl::core::IPV6_ADDRESS addr) const;

    public:

        static IPV4_ADDRESS ipStrToAddr(std::string add);

        static std::string ipAddrToStr(IPV4_ADDRESS add);


        static IPV6_ADDRESS ipv6StrToAddr(std::string add);

        static std::string ipv6AddrToStr(IPV6_ADDRESS add);

        static std::string macAddrToStr(MAC_ADDRESS add);


        static MAC_ADDRESS macStrToAddr(std::string add);

    private:


        /**
         * 分配mac地址,如果
         * */
        MAC_ADDRESS allocMac(vl::core::MAC_ADDRESS expect = EMPTY_MAC);

        /**
         * 分配ip地址
         * @return
         */
        IPV4_ADDRESS allocIp(vl::core::IPV4_ADDRESS expect = EMPTY_IP);

        /**
         * 分配ipv6地址
         * @return
         */
        IPV6_ADDRESS allocIpv6(vl::core::IPV6_ADDRESS expect = EMPTY_IPV6);

        IPV4_ADDRESS nextIp() const;

        MAC_ADDRESS nextMac() const;

    private:

        static Byte strHexToByte(Byte str);

        static BYTE_ARRAY<2> byteToStrHex(Byte str);


    private:


        /**
         * ip分配范围
         */
        std::pair<vl::core::IPV4_ADDRESS/*start*/, vl::core::IPV4_ADDRESS/*end*/> _ipRange;


        /**
         * ipv6分配范围
         */
        std::pair<vl::core::IPV6_ADDRESS/*start*/, vl::core::IPV6_ADDRESS/*end*/> _ipv6Range;

        /**
         * 使用ipv6
         */
        bool _useIpv6 = false;


        /**
         * 客户端客户端id与虚拟ip的映射
         */
        std::unordered_map<vl::core::MAC_ADDRESS /*mac*/, std::shared_ptr<vl::core::Device>, vl::core::AddressHasher<MAC_LEN>> _macDeviceMap = std::unordered_map<vl::core::MAC_ADDRESS/*mac*/, std::shared_ptr<vl::core::Device>, vl::core::AddressHasher<MAC_LEN>>(
                1024);


        /**
         * 已经分配的ip
         */
        std::unordered_set<vl::core::IPV4_ADDRESS, vl::core::AddressHasher<IPV4_LEN>> _allocedIp = std::unordered_set<vl::core::IPV4_ADDRESS, vl::core::AddressHasher<IPV4_LEN>>(
                1024);

        /**
         * 已经分配的ipv6
         */
        std::unordered_set<vl::core::IPV6_ADDRESS, vl::core::AddressHasher<IPV6_LEN>> _allocedIpv6 = std::unordered_set<vl::core::IPV6_ADDRESS, vl::core::AddressHasher<IPV6_LEN>>(
                1024);

        /**
         * 已经分配的mac地址
         */
        std::unordered_set<vl::core::MAC_ADDRESS, vl::core::AddressHasher<MAC_LEN>> _allocedMac = std::unordered_set<vl::core::MAC_ADDRESS, vl::core::AddressHasher<MAC_LEN>>(
                1024);


    };


}


#endif //VIRTUALLAN_ETHERNETADDRESSMANAGER_H
