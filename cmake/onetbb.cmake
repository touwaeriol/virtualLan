

include(CPM)


CPMAddPackage("gh:oneapi-src/oneTBB#v2021.5.0")

#库名称
set(ONETBB_LIB_NAME tbb)
set(ONETBB_LIB_INCLUDE ${onetbb_SOURCE_DIR}/include)

