cmake_minimum_required(VERSION 3.20)
project(LogicLib)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_LIB Position.cpp)
add_library(Logic SHARED ${SOURCE_LIB})
