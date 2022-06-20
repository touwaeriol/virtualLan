
set(TARGET_NAME core)

#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便

FILE(GLOB_RECURSE SOURCES ./*.cpp  ./*.cc)





message("core_source " ${SOURCES})


add_library(${TARGET_NAME} STATIC ${SOURCES})


target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_PATH}/include/vl/core ${PROJECT_PATH}/include/vl/core/rpc)


include(grpcpp)
include(libtuntap)
include(asio)
include(stduuid)
include(concurrentqueue)
include(cocoyaxi)


SET(LIBS
        ${GRPCPP_LIB_NAME}
        ${LIBTUNTAP_LIB_NAME}
        ${ASIO_LIB_NAME}
        ${STDUUID_LIB_NAME}
        ${CONCURRENTQUEUE_LIB_NAME}
        ${COCOYAXI_LIB_NAME}

        )
SET(INCLUDES
        ${GRPCPP_LIB_INCLUDE}
        ${ASIO_LIB_INCLUDE}
        ${STDUUID_LIB_INCLUDE}
        ${LIBTUNTAP_LIB_INCLUDE}
        ${CONCURRENTQUEUE_LIB_INCLUDE}
        ${COCOYAXI_LIB_INCLUDE}

        )
target_link_libraries(${TARGET_NAME} ${LIBS})
target_include_directories(${TARGET_NAME}
        PUBLIC
        ${INCLUDES}
        )
