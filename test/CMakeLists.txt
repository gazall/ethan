cmake_minimum_required(VERSION 2.8)

ADD_EXECUTABLE(log_test log_test.cc)
TARGET_LINK_LIBRARIES(log_test ethan_base pthread)

#ADD_EXECUTABLE(nocopyable_test nocopyable_test.cc)
#TARGET_LINK_LIBRARIES(nocopyable_test ethan_base)

ADD_EXECUTABLE(exception_test exception_test.cc)

ADD_EXECUTABLE(server_test server_test.cc)
TARGET_LINK_LIBRARIES(server_test ethan_base ethan_net)