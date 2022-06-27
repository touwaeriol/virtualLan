include(CPM)


CPMAddPackage("gh:cameron314/concurrentqueue#v1.0.3")
CPMAddPackage("gh:cameron314/readerwriterqueue#v1.0.6")



set(CONCURRENTQUEUE_LIB_NAME concurrentqueue readerwriterqueue)
set(CONCURRENTQUEUE_LIB_INCLUDE ${concurrentqueue_SOURCE_DIR} ${readerwriterqueue_SOURCE_DIR})




