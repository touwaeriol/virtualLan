#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便
#FILE(SOURCES *.cpp)

aux_source_directory(. SOURCES)
#头文件 GLOB 只遍历目标文件夹，  GLOB_RECURSE 递归遍历目标文件夹
FILE(GLOB_RECURSE HEADERS ${PROJECT_PATH}/include/server/*.h)
#源代码文件

#可执行文件
add_executable(server-test1 main.cpp ${HEADERS})
#链接tuntap
target_link_libraries(server-test1 PRIVATE tuntap++)
#包含头文件
include_directories(server-test1 PRIVATE ${PROJECT_PATH}/include/tuntap)