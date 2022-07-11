
set(TARGET_NAME core)

#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便

FILE(GLOB_RECURSE SOURCES ./*.cpp ./*.cc)


add_library(${TARGET_NAME} STATIC ${SOURCES})


target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_PATH}/include/vl/core ${PROJECT_PATH}/include/vl/core/rpc)


include(grpcpp)
include(libtuntap)
include(concurrentqueue)
include(googletest)
include(spdlog)
include(gflags)
include(boost)
include(onetbb)
include(fmt)
include(asyncpluscplus)
include(kcp)
include(yasio)


SET(LIBS
        ${GRPCPP_LIB_NAME}
        ${LIBTUNTAP_LIB_NAME}
        ${CONCURRENTQUEUE_LIB_NAME}
        ${GOOGLETEST_LIB_NAME}
        ${SPDLOG_LIB_NAME}
        ${GFLAGS_LIB_NAME}
        ${BOOST_EXCEPTION_LIB_NAME}
        ${BOOST_UUID_LIB_NAME}
        ${BOOST_ASIO_LIB_NAME}
        ${ONETBB_LIB_NAME}
        ${FMT_LIB_NAME}
        ${ASYNCPLUSPLUS_LIB_NAME}
        ${KCP_LIB_NAME}
        ${YASIO_LIB_NAME}

        )
target_link_libraries(${TARGET_NAME} ${LIBS})


SET(INCLUDES
        ${GRPCPP_LIB_INCLUDE}
        ${LIBTUNTAP_LIB_INCLUDE}
        ${CONCURRENTQUEUE_LIB_INCLUDE}
        ${GOOGLETEST_LIB_INCLUDE}
        ${SPDLOG_LIB_INCLUDE}
        ${GFLAGS_LIB_INCLUDE}
        ${BOOST_EXCEPTION_LIB_INCLUDE}
        ${BOOST_UUID_LIB_INCLUDE}
        ${BOOST_ASIO_LIB_INCLUDE}
        ${ONETBB_LIB_INCLUDE}
        ${FMT_LIB_INCLUDE}
        ${ASYNCPLUSPLUS_LIB_INCLUDE}
        ${KCP_LIB_INCLUDE}
        ${YASIO_LIB_INCLUDE}

        )
target_include_directories(${TARGET_NAME}
        PUBLIC
        ${INCLUDES}
        )

