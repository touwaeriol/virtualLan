
include(FetchContent)
FetchContent_Declare(
        stduuid
        GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
        GIT_TAG v1.2.2
)
FetchContent_MakeAvailable(stduuid)


#库名称
set(STDUUID_LIB_NAME stduuid)
set(STDUUID_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/stduuid-src/include)