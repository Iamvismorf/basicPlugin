project(basicPlugin)
cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_library(basic SHARED main.cpp)
