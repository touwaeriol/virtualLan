



include(CPM)

CPMAddPackage("gh:touwaeriol/libtuntap#v0.5.0@v0.5.0")



#库名称
set(LIBTUNTAP_LIB_NAME tuntap tuntap++)

set(LIBTUNTAP_LIB_INCLUDE ${libtuntap_SOURCE_DIR} ${libtuntap_SOURCE_DIR}/bindings/cpp)
