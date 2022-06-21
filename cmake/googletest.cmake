

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)


set(GOOGLETEST_LIB_NAME googletest)
set(GOOGLETEST_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/googletest-src/include)

