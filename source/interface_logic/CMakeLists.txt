cmake_minimum_required(VERSION 3.16)
project(InterfaceLib)
set(CMAKE_CXX_STANDARD 17)

set(ACTIONS_LIB   action/Action.cpp
                  action/actions_types/CancelMove.cpp
                  action/actions_types/OfferDraw.cpp
                  action/actions_types/MakeMove.cpp
                  action/actions_types/Surrender.cpp)

set(INTERFACE_LIB interface/Interface.cpp
                  interface/Window.cpp
                  interface/windows_types/GameWindow.cpp
                  interface/windows_types/MenuWindow.cpp)

set(WRAPPERS_LIB  wrappers/PieceWrapper.cpp
                  wrappers/PositionWrapper.cpp)

set(HEAD_LIB      Head.cpp)

add_library(Interface SHARED ${ACTIONS_LIB} ${INTERFACE_LIB} ${WRAPPERS_LIB} ${HEAD_LIB})
