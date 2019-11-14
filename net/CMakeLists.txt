cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

SET(SRC_LIST
    Address.cc
    )


ADD_LIBRARY(net STATIC ${SRC_LIST})
#ADD_LIBRARY(net SHARED ${SRC_LIST})
