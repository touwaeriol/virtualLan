
set(TARGET_NAME udp)

add_executable(${TARGET_NAME} main.cpp)


SET(CORE_TARGET_NAME core)
target_link_libraries(${TARGET_NAME} ${CORE_TARGET_NAME})