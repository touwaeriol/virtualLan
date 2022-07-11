



add_executable(test_async++ main.cpp)

target_include_directories(test_async++ PRIVATE ${PROJECT_PATH}/include/)
target_link_libraries(test_async++ core)