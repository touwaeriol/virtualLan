
set(TARGET_NAME client)

#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便
#头文件 GLOB 只遍历目标文件夹，  GLOB_RECURSE 递归遍历目标文件夹
#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便
FILE(GLOB_RECURSE SOURCES ./*.cpp)

add_executable(${TARGET_NAME}
        ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_PATH}/include/vl/${TARGET_NAME}  ${PROJECT_PATH}/include/)


SET(CORE_TARGET_NAME core)
target_link_libraries(${TARGET_NAME} ${CORE_TARGET_NAME})

#include(grpcpp)
#include(libtuntap)
#include(hiredis)
#include(cocoyaxi)
#include(stduuid)
#
#SET(LIBS
#        ${GRPCPP_LIB_NAME}
#        ${LIBTUNTAP_LIB_NAME}
#        ${HIREDIS_LIB_NAME}
#        ${COCOYAXI_LIB_NAME}
#        ${STDUUID_LIB_NAME}
#        )
#SET(INCLUDES
#        ${GRPCPP_LIB_INCLUDE}
#        ${LIBTUNTAP_LIB_INCLUDE}
#        ${HIREDIS_LIB_INCLUDE}
#        ${COCOYAXI_LIB_INCLUDE}
#        ${STDUUID_LIB_INCLUDE}
#        )
#
#target_link_libraries(${TARGET_NAME} ${LIBS})
#target_include_directories(${TARGET_NAME}
#        PUBLIC
#        ${INCLUDES}
#        )
