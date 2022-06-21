

include(FetchContent)
FetchContent_Declare(
        gflags
        GIT_REPOSITORY https://github.com/gflags/gflags.git
        GIT_TAG v2.2.2
)

FetchContent_MakeAvailable(gflags)


set(GFLAGS_LIB_NAME gflags)
set(GFLAGS_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/gflags-src/include)

