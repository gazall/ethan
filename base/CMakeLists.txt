cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

SET(SRC_LIST
    easylogging++.cc
    )


ADD_LIBRARY(ethan_basic STATIC ${SRC_LIST})
