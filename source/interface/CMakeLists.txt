cmake_minimum_required(VERSION 3.16)
project(InterfaceLib)
set(CMAKE_CXX_STANDARD 17)

set(ACTIONS_LIB   action/Action.cpp
        action/CancelMove.cpp
        action/MakeMove.cpp
        action/Surrender.cpp)

set(INTERFACE_LIB console_interface/Interface.cpp
        console_interface/windows/Window.cpp
        console_interface/windows/GameWindow.cpp
        console_interface/windows/MenuWindow.cpp)

set(WRAPPERS_LIB  wrappers/PieceWrapper.cpp
                  wrappers/PositionWrapper.cpp)

set(HEAD_LIB      Head.cpp)

add_library(Interface SHARED ${ACTIONS_LIB} ${INTERFACE_LIB} ${WRAPPERS_LIB} ${HEAD_LIB})
