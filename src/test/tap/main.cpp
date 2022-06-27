//
// Created by touwaerio on 2022/6/15.
//

#include <vl/core.h>


TEST(TAP, CREATE) {

    auto tap = std::make_unique<vl::core::Tap>();

    tap->up();

    auto ip = "192.168.100.4";
    auto netmask = 24;
    auto name = "tap0";
    auto mtu = 1474;

    tap->ip(ip, netmask);
    tap->name(name);

    tap->mtu(mtu);

    auto tapIp = tap->ip();
    EXPECT_EQ(name, tap->name());
    EXPECT_EQ(mtu, tap->mtu());

    tap->down();

    tap.release();
}




GTEST_API_ int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
