include(FetchContent)
FetchContent_Declare(
        hiredis
        GIT_REPOSITORY https://github.com/redis/hiredis.git
        GIT_TAG v1.0.2
)
FetchContent_MakeAvailable(hiredis)

set(HIREDIS_LIB_NAME hiredis)
set(HIREDIS_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/hiredis-src/include)


