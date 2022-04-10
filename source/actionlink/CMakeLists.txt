cmake_minimum_required(VERSION 3.16)
project(MainLib)
set(CMAKE_CXX_STANDARD 17)

set(ACTION_LIB      Action.cpp)

add_library(Actions SHARED ${ACTION_LIB})
