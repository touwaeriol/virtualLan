
set(TARGET_NAME server)

#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便
#aux_source_directory(. SOURCES)
FILE(GLOB_RECURSE SOURCES ./*.cpp )
#头文件 GLOB 只遍历目标文件夹，  GLOB_RECURSE 递归遍历目标文件夹
#将当前目录下所有源文件赋给MATH_SOURCE变量，当源文件数量比较多时会比较方便


add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_PATH}/include/vl/${TARGET_NAME}  ${PROJECT_PATH}/include/)


SET(CORE_TARGET_NAME core)
target_link_libraries(${TARGET_NAME} ${CORE_TARGET_NAME})

