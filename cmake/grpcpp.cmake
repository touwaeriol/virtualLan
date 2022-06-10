#find_library(grpc++ grpc++)

include(FetchContent)
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG        v1.46.2
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)


set(GRPCPP_LIB_NAME grpc++)
set(GRPCPP_LIB_INCLUDE ${CMAKE_BINARY_DIR}/_deps/grpc-src/include)

