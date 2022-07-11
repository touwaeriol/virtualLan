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

    class Server;
}


namespace vl::server {
    using namespace vl::core;

    /**
     * 网络地址管理器，一个分组一个管理器
     */
    class EthernetAddressManager : public Uncopymovable {
        friend class Server;


    public:
        EthernetAddressManager(const pair<IPV4_ADDRESS, IPV4_ADDRESS> &ipRange,
                               const pair<IPV6_ADDRESS, IPV6_ADDRESS> &ipv6Range);


        EthernetAddressManager(const pair<std::string, std::string> &ipRange,
                               const pair<std::string, std::string> &ipv6Range
        );

        EthernetAddressManager(pair<IPV4_ADDRESS, IPV4_ADDRESS> ipRange);


        EthernetAddressManager(const pair<std::string, std::string> &ipRange);

        ~EthernetAddressManager() override = default;

    public:
        std::shared_ptr<Device> allocDevice(const string & clientId,const string & publicId,const string & group);


        bool macInUse(MAC_ADDRESS addr) const;


        bool ipInUse(IPV4_ADDRESS addr) const;


        bool ipv6InUse(IPV6_ADDRESS addr) const;

        const tbb::concurrent_unordered_map<MAC_ADDRESS, std::shared_ptr<Device>, AddressHasher<6>, AddressEquals<6>> &
        getMacDeviceMap() const;

    public:

        static IPV4_ADDRESS ipStrToAddr(const std::string &add);

        static std::string ipAddrToStr(IPV4_ADDRESS add);


        static IPV6_ADDRESS ipv6StrToAddr(const std::string &add);

        static std::string ipv6AddrToStr(IPV6_ADDRESS add);

        static std::string macAddrToStr(MAC_ADDRESS add);

        static MAC_ADDRESS macStrToAddr(const std::string &add);


    private:


        /**
         * 分配mac地址,如果
         * */
        MAC_ADDRESS allocMac(MAC_ADDRESS expect = EMPTY_MAC);

        /**
         * 分配ip地址
         * @return
         */
        IPV4_ADDRESS allocIp(IPV4_ADDRESS expect = EMPTY_IP);

        /**
         * 分配ipv6地址
         * @return
         */
        IPV6_ADDRESS allocIpv6(IPV6_ADDRESS expect = EMPTY_IPV6);

        IPV4_ADDRESS nextIp() const;

        MAC_ADDRESS nextMac() const;

        /**
         * 设置mac地址对应的udp端口
         * @param mac
         * @param port
         * @return
         */
        std::pair<bool, string> setDeviceUdpPort(MAC_ADDRESS mac, uint32_t port);

        /**
         * 根据mac地址获取信息
         * @param mac
         * @return
         */
        std::optional<pair<IPV4_ADDRESS, uint32_t>> getDevicePublicAddr(MAC_ADDRESS mac);

    private:

        static Byte strHexToByte(Byte str);

        static BYTE_ARRAY<2> byteToStrHex(Byte str);


    private:


        /**
         * ip分配范围
         */
        std::pair<IPV4_ADDRESS/*start*/, IPV4_ADDRESS/*end*/> _ipRange;


        /**
         * ipv6分配范围
         */
        std::pair<IPV6_ADDRESS/*start*/, IPV6_ADDRESS/*end*/> _ipv6Range;

        /**
         * 使用ipv6
         */
        bool _useIpv6 = false;

        /**
         * 客户端客户端id与虚拟ip的映射
         */
        oneapi::tbb::concurrent_unordered_map<MAC_ADDRESS /*mac*/, std::shared_ptr<Device>,
                AddressHasher<MAC_LEN>, AddressEquals<MAC_LEN>> _macDeviceMap{
                1024
        };


        /**
         * 已经分配的ip
         */
        oneapi::tbb::concurrent_unordered_set<IPV4_ADDRESS,
                AddressHasher<IPV4_LEN>, AddressEquals<IPV4_LEN>> _allocedIp{
                1024
        };

        /**
         * 已经分配的ipv6
         */
        oneapi::tbb::concurrent_unordered_set<IPV6_ADDRESS,
                AddressHasher<IPV6_LEN>, AddressEquals<IPV6_LEN>> _allocedIpv6{
                1024
        };

        /**
         * 已经分配的mac地址
         */
        oneapi::tbb::concurrent_unordered_set<MAC_ADDRESS,
                AddressHasher<MAC_LEN>, AddressEquals<MAC_LEN>> _allocedMac{
                1024
        };

    };


}


#endif //VIRTUALLAN_ETHERNETADDRESSMANAGER_H
