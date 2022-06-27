include(CPM)

CPMAddPackage("gh:gflags/gflags#v2.2.2")


set(GFLAGS_LIB_NAME gflags)
set(GFLAGS_LIB_INCLUDE ${gflags_SOURCE_DIR}/include)

