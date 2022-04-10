cmake_minimum_required(VERSION 3.16)
project(MainLib)
set(CMAKE_CXX_STANDARD 17)

set(WINDOWS_LIB windows/GameWindow.cpp
                windows/MenuWindow.cpp)

set(INTERFACE_LIB    Interface.cpp)

add_library(Interface SHARED ${WINDOWS_LIB} ${INTERFACE_LIB})
