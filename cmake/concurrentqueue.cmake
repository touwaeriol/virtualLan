include(FetchContent)

FetchContent_Declare(concurrentqueue
        GIT_REPOSITORY https://github.com/cameron314/concurrentqueue.git
        GIT_TAG v1.0.3
        )

FetchContent_MakeAvailable(concurrentqueue)


set(CONCURRENTQUEUE_LIB_NAME concurrentqueue)
set(CONCURRENTQUEUE_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/concurrentqueue-src)
