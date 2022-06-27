include(CPM)


CPMAddPackage("gh:gabime/spdlog#v1.10.0")

#库名称
set(SPDLOG_LIB_NAME spdlog)
set(SPDLOG_LIB_INCLUDE  ${spdlog_SOURCE_DIR}/include)