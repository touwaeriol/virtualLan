include(CPM)

CPMAddPackage("gh:yasio/yasio#v3.39.4")

set(YASIO_LIB_NAME yasio)
set(YASIO_LIB_INCLUDE ${yasio_SOURCE_DIR}/include)


#                   启用kcp支持      仅头文件模式          启用 打开和关闭连接事件
add_definitions("-DYASIO_HAVE_KCP -DYASIO_HEADER_ONLY -DYASIO_ENABLE_PASSIVE_EVENT")
