

include(CPM)


CPMAddPackage("gh:google/googletest#release-1.11.0")



set(GOOGLETEST_LIB_NAME gtest)
set(GOOGLETEST_LIB_INCLUDE ${googletest_SOURCE_DIR}/googletest/include)




