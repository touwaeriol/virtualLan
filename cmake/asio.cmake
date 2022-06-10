
include(FetchContent)

FetchContent_Declare(asio-cmake
        GIT_REPOSITORY https://github.com/kingsamchen/asio-cmake.git
        GIT_TAG        origin/master
        )

# Specify asio version
set(ASIO_CMAKE_ASIO_TAG asio-1-22-1)
FetchContent_MakeAvailable(asio-cmake)


set(ASIO_LIB_NAME asio)
set(ASIO_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/asio-cmake-src/asio-${ASIO_CMAKE_ASIO_TAG}-src/asio/include)
