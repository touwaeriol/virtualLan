#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便
#FILE(SOURCES *.cpp)

aux_source_directory(. SOURCES)
#头文件 GLOB 只遍历目标文件夹，  GLOB_RECURSE 递归遍历目标文件夹
FILE(GLOB_RECURSE HEADERS ${PROJECT_PATH}/include/server/*.h ${PROJECT_PATH}/src/server/test/test2/*.h)

#message("test2 头文件" ${HEADERS})
#message("test2 源文件" ${SOURCES})
#源代码文件

#可执行文件
add_executable(server-test2 ${SOURCES} ${HEADERS})



target_link_libraries(server-test2 PRIVATE tuntap++ grpc++)
#链接grpc++
target_link_libraries(server-test2 gRPC::grpc++)



