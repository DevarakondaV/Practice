cmake_minimum_required (VERSION 2.6)
project(Tree)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(include)
add_subdirectory(src)
