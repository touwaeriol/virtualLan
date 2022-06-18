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
        EthernetAddressManager(pair<IPV4_ADDRESS, IPV4_ADDRESS> ipRange,
                               pair<IPV6_ADDRESS, IPV6_ADDRESS> ipv6Range);


        EthernetAddressManager(pair<std::string, std::string> ipRange,
                               pair<std::string, std::string> ipv6Range
        );

        EthernetAddressManager(pair<IPV4_ADDRESS, IPV4_ADDRESS> ipRange);


        EthernetAddressManager(pair<std::string, std::string> ipRange);

        ~EthernetAddressManager() override = default;

    public:
        std::shared_ptr<Device> allocDevice();


        bool macInUse(MAC_ADDRESS addr) const;


        bool ipInUse(IPV4_ADDRESS addr) const;


        bool ipv6InUse(IPV6_ADDRESS addr) const;


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
        std::pair<bool, string> setDeviceUdpPort(MAC_ADDRESS mac, uint32 port);


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

        Mutex _mutex;

        /**
         * 客户端客户端id与虚拟ip的映射
         */
        unordered_map<MAC_ADDRESS /*mac*/, shared_ptr<Device>, AddressHasher<MAC_LEN>, AddressEquals<MAC_ADDRESS>> _macDeviceMap{
                1024};

        /**
         * 已经分配的ip
         */
        unordered_set<IPV4_ADDRESS, AddressHasher<IPV4_LEN>, AddressEquals<IPV4_ADDRESS>> _allocedIp{1024};

        /**
         * 已经分配的ipv6
         */
        unordered_set<IPV6_ADDRESS, AddressHasher<IPV6_LEN>, AddressEquals<IPV6_ADDRESS>> _allocedIpv6{1024};

        /**
         * 已经分配的mac地址
         */
        unordered_set<MAC_ADDRESS, AddressHasher<MAC_LEN>, AddressEquals<MAC_ADDRESS>> _allocedMac{1024};

    };


}


#endif //VIRTUALLAN_ETHERNETADDRESSMANAGER_H
