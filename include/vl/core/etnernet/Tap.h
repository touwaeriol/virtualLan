//
// Created by touwaerio on 2022/6/1.
//

#ifndef VIRTUALLAN_TAP_H
#define VIRTUALLAN_TAP_H

#include <string>
#include <tuntap++.hh>
#include "../util/Uncopymovable.hpp"


namespace vl::core {
    class Tap;

}


namespace vl::core {
    class Tap : public Uncopymovable {

    public:
        Tap();

        ~Tap() override;

    public:
        std::string name() const;

        /**
         * 网卡名称长度 [3,16]
         * @param string
         */
        void name(const std::string &string);

        std::string hwaddr() const;

        void hwaddr(const std::string &string);

        int mtu() const;

        void mtu(int i);

//        t_tun native_handle() const ;

        void up();

        void down();


        std::string ip();

        /**
         * 设置ipv4地址子网掩码为0-32
         * @param presentation
         * @param netmask
         */
        void ip(const std::string &ip, int netmask);

        std::string ipv6();

        /**
         * 设置ipv6地址，前缀长度0-128
         * @param ipv6
         * @param netmask
         */
        void ipv6(const std::string &ipv6, int prefixLength);

        int read(void *buf, size_t len);

        int write(void *buf, size_t len);

        void release();

        void nonblocking(bool b);


    private:
        std::string _ip;

        std::string _ipv6;

        tuntap::tap _tap;
    };

}




#endif //VIRTUALLAN_TAP_H
