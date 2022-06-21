
include(FetchContent)
FetchContent_Declare(
        onetbb
        GIT_REPOSITORY https://github.com/oneapi-src/oneTBB.git
        GIT_TAG v2021.5.0
)
FetchContent_MakeAvailable(onetbb)

#库名称
set(ONETBB_LIB_NAME onetbb)
set(ONETBB_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/onetbb-src/include)