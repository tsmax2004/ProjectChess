cmake_minimum_required(VERSION 3.20)
project(LogicLib)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_LIB Position.cpp Game.cpp
        figures/Pawn.cpp figures/Bishop.cpp figures/Empty.cpp figures/King.cpp figures/Knight.cpp
        figures/Queen.cpp figures/Rook.cpp moves/InvalidMove.cpp)
add_library(Logic SHARED ${SOURCE_LIB})
