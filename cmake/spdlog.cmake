
include(FetchContent)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.10.0
)
FetchContent_MakeAvailable(spdlog)


#库名称
set(SPDLOG_LIB_NAME spdlog)
set(SPDLOG_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/spdlog-src/include)