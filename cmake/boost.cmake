include(CPM)

CPMAddPackage("gh:boostorg/boost#boost-1.79.0")

SET(ASIO asio)
SET(ARRAY array)
SET(ASSERT assert)
SET(BIND bind)
SET(CHRONO chrono)
SET(CONFIG config)
SET(CORE core)
SET(COROUTINE coroutine)
SET(DATE_TIME date_time)
SET(FUNCTION function)
SET(REGEX regex)
SET(THROW_EXCEPTION throw_exception)
SET(UTILITY utility)
SET(EXCEPTION exception)
SET(UUID uuid)
SET(FORMAT format)
SET(LOG log)




set(BOOST_ASIO_LIB_NAME Boost::${ASIO})
set(BOOST_EXCEPTION_LIB_NAME Boost::${EXCEPTION})
set(BOOST_UUID_LIB_NAME Boost::${UUID})
set(BOOST_FORMAT_LIB_NAME Boost::${FORMAT})
set(BOOST_LOG_LIB_NAME Boost::${LOG})

set(BOOST_ASIO_LIB_INCLUDE ${boost_SOURCE_DIR}/libs/${ASIO}/include)
set(BOOST_EXCEPTION_LIB_INCLUDE ${boost_SOURCE_DIR}/libs/${EXCEPTION}/include)
set(BOOST_UUID_LIB_INCLUDE ${boost_SOURCE_DIR}/libs/${UUID}/include)
set(BOOST_FORMAT_LIB_INCLUDE ${boost_SOURCE_DIR}/libs/${FORMAT}/include)
set(BOOST_LOG_LIB_INCLUDE ${boost_SOURCE_DIR}/libs/${LOG}/include)
