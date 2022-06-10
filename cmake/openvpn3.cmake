
include(FetchContent)
FetchContent_Declare(
        openvpn3
        GIT_REPOSITORY https://github.com/OpenVPN/openvpn3.git
        GIT_TAG release/3.7
)
FetchContent_MakeAvailable(openvpn3)

include(asio)
#添加使用asio的宏定义，不然找不到openvpn_io命名空间
add_definitions("-DUSE_ASIO")
#还需要在include openvpn代码的前面引入日志头文件
#include <openvpn/log/logsimple.hpp>

SET(OPENVPN3_LIB_NAME ${ASIO_LIB_NAME})
SET(OPENVPN3_LIB_INCLUDE ${ASIO_LIB_INCLUDE} ${CMAKE_BINARY_DIR}/_deps/openvpn3-src)

