cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

SET(SRC_LIST
    easylogging++.cc
    log_wrapper.cc
    )


ADD_LIBRARY(ethan_base STATIC ${SRC_LIST})
TARGET_LINK_LIBRARIES(ethan_base pthread)