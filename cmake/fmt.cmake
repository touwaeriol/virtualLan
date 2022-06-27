
include(CPM)

CPMAddPackage("gh:fmtlib/fmt#8.1.1")

set(FMT_LIB_NAME fmt)
set(FMT_LIB_INCLUDE ${fmt_SOURCE_DIR}/include)