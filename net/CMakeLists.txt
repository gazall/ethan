cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

SET(SRC_LIST
    Address.cc
    )


ADD_LIBRARY(ethan_net STATIC ${SRC_LIST})
TARGET_LINK_LIBRARIES(ethan_net ethan_base)
