cmake_minimum_required(VERSION 2.8)
#add_compile_options(-std=c++11)
SET(CMAKE_CXX_FLAGS -std=c++11)

PROJECT(ethan)
INCLUDE_DIRECTORIES(./)

ADD_SUBDIRECTORY(base)
ADD_SUBDIRECTORY(net)
ADD_SUBDIRECTORY(test)