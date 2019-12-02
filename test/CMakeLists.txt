cmake_minimum_required(VERSION 2.8)

ADD_EXECUTABLE(log_test log_test.cc)
TARGET_LINK_LIBRARIES(log_test ethan_base pthread)

#ADD_EXECUTABLE(nocopyable_test nocopyable_test.cc)
#TARGET_LINK_LIBRARIES(nocopyable_test ethan_base)
