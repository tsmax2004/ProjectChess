cmake_minimum_required(VERSION 3.16)
project(LogicLib)
set(CMAKE_CXX_STANDARD 17)

set(CLASSIC_PIECES_LIB
        pieces/ClassicalPieces/Pawn.cpp
        pieces/ClassicalPieces/Bishop.cpp
        pieces/ClassicalPieces/King.cpp
        pieces/ClassicalPieces/Knight.cpp
        pieces/ClassicalPieces/Queen.cpp
        pieces/ClassicalPieces/Rook.cpp)
set(ATOMIC_PIECES_LIB
        pieces/AtomicPieces/AtomicPawn.cpp
        pieces/AtomicPieces/AtomicBishop.cpp
        pieces/AtomicPieces/AtomicKing.cpp
        pieces/AtomicPieces/AtomicKnight.cpp
        pieces/AtomicPieces/AtomicQueen.cpp
        pieces/AtomicPieces/AtomicRook.cpp)

set(DEFAULT_PIECES_LIB pieces/Piece.cpp
        pieces/Empty.cpp)
set(SOURCE_LIB Position.cpp GameLogic.cpp)

set(MOVES_LIB moves/InvalidMove.cpp
        moves/AtomicMoves/AtomicSimpleMove.cpp
        moves/AtomicMoves/AtomicCastle.cpp
        moves/AtomicMoves/AtomicEnPassant.cpp
        moves/AtomicMoves/AtomicPromotion.cpp
        moves/ClassicalMoves/Castle.cpp
        moves/ClassicalMoves/SimpleMove.cpp
        moves/ClassicalMoves/EnPassant.cpp
        moves/ClassicalMoves/Promotion.cpp)

add_library(Logic SHARED ${SOURCE_LIB} ${DEFAULT_PIECES_LIB} ${CLASSIC_PIECES_LIB} ${ATOMIC_PIECES_LIB} ${MOVES_LIB})
