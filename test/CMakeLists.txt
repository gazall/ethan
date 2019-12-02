cmake_minimum_required(VERSION 2.8)

ADD_EXECUTABLE(log_test log_test.cc)
TARGET_LINK_LIBRARIES(log_test ethan_base pthread)

#ADD_EXECUTABLE(nocopable_test nocopable_test.cc)
#TARGET_LINK_LIBRARIES(nocopable_test ethan_base)