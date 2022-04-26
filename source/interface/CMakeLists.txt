cmake_minimum_required(VERSION 3.16)
project(MainLib)
set(CMAKE_CXX_STANDARD 17)

set(WINDOWS_LIB windows/GameWindow.cpp
        )

set(INTERFACE_LIB    Interface.cpp)

set(CONSOLE_LIB console/windows/MenuWindowConsole.cpp
                console/windows/GameWindowConsole.cpp)

add_library(Interface SHARED ${WINDOWS_LIB} ${INTERFACE_LIB} ${CONSOLE_LIB})
