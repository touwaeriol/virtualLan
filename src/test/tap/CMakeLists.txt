
set(TARGET_NAME tap)

add_executable(${TARGET_NAME} main.cpp)


SET(CORE_TARGET_NAME core)
target_link_libraries(${TARGET_NAME} ${CORE_TARGET_NAME})
target_include_directories(${TARGET_NAME}  PRIVATE ${PROJECT_PATH}/include/)