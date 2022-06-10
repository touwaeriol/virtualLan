include(FetchContent)

FetchContent_Declare(cocoyaxi
        GIT_REPOSITORY https://github.com/idealvin/cocoyaxi.git
        GIT_TAG v2.0.3
        )

FetchContent_MakeAvailable(cocoyaxi)


set(COCOYAXI_LIB_NAME co)
set(COCOYAXI_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/cocoyaxi-src/include)
