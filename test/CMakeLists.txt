cmake_minimum_required(VERSION 2.8)

SET(SRC_LIST
    log_test.cc
    )

ADD_EXECUTABLE(log_test ${SRC_LIST})
TARGET_LINK_LIBRARIES(log_test ethan_base pthread)