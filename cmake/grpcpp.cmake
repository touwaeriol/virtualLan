

include(CPM)



CPMAddPackage(
        NAME grpc
        VERSION v1.46.2
        DOWNLOAD_ONLY false
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG v1.46.2
        OPTIONS
        "FETCHCONTENT_QUIET OFF"
        "ABSL_PROPAGATE_CXX_STD ON"
)


set(GRPCPP_LIB_NAME grpc++)
set(GRPCPP_LIB_INCLUDE ${grpcpp_SOURCE_DIR}/include)

