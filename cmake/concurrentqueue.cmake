include(FetchContent)

FetchContent_Declare(concurrentqueue
        GIT_REPOSITORY https://github.com/cameron314/concurrentqueue.git
        GIT_TAG v1.0.3
        )



FetchContent_MakeAvailable(concurrentqueue)


FetchContent_Declare(
        readerwriterqueue
        GIT_REPOSITORY    https://github.com/cameron314/readerwriterqueue
        GIT_TAG           v1.0.6
)
FetchContent_MakeAvailable(readerwriterqueue)

set(CONCURRENTQUEUE_LIB_NAME concurrentqueue readerwriterqueue)
set(CONCURRENTQUEUE_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/concurrentqueue-src ${CMAKE_BINARY_DIR}/_deps/readerwriterqueue-src)




