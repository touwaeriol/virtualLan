cmake_minimum_required(VERSION 3.11)
project(virtualLan VERSION 1.0.0)
set(PROJECT_VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)


set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)
message("项目路径: " ${PROJECT_PATH})


#设置顶层cmakelist路径
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message("PROJECT_PATH: " ${PROJECT_PATH})

#编译结果放入顶层的构建文件夹下
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#添加cmake搜索路径
set(CMAKE_MODULE_PATH ;${PROJECT_PATH}/cmake)
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})

#设置调试参数以识别std::string类型
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")



#添加子层级
add_subdirectory(src)










