cmake_minimum_required(VERSION 3.16)
project(LogicLib)
set(CMAKE_CXX_STANDARD 17)

set(PIECES_LIB pieces/Piece.cpp
               pieces/Pawn.cpp
               pieces/Bishop.cpp
               pieces/Empty.cpp
               pieces/King.cpp
               pieces/Knight.cpp
               pieces/Queen.cpp
               pieces/Rook.cpp)

set(SOURCE_LIB Position.cpp GameLogic.cpp)

set(MOVES_LIB moves/InvalidMove.cpp moves/SimpleMove.cpp moves/Castle.cpp moves/EnPassant.cpp moves/Promotion.cpp)

add_library(Logic SHARED ${SOURCE_LIB} ${PIECES_LIB} ${MOVES_LIB})
