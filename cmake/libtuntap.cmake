include(FetchContent)
FetchContent_Declare(
        libtuntap
        GIT_REPOSITORY https://github.com/touwaeriol/libtuntap.git
        GIT_TAG v0.5.0
)
FetchContent_MakeAvailable(libtuntap)


#库名称
set(LIBTUNTAP_LIB_NAME tuntap tuntap++)

set(LIBTUNTAP_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/libtuntap-src/ ${CMAKE_BINARY_DIR}/_deps/libtuntap-src/bindings/cpp)