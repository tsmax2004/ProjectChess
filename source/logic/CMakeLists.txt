cmake_minimum_required(VERSION 3.20)
project(LogicLib)
set(CMAKE_CXX_STANDARD 20)

set(PIECES_LIB figures/Pawn.cpp figures/Bishop.cpp figures/Empty.cpp figures/King.cpp figures/Knight.cpp figures/Queen.cpp figures/Rook.cpp)

set(SOURCE_LIB Position.cpp Game.cpp)

set(MOVES_LIB moves/InvalidMove.cpp moves/SimpleMove.cpp moves/Castle.cpp moves/EnPassant.cpp moves/Promotion.cpp)

add_library(Logic SHARED ${SOURCE_LIB} ${PIECES_LIB} ${MOVES_LIB})
