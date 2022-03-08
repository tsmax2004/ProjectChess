
#ifndef ENUMS_H_
#define ENUMS_H_

enum COLOR: char { WHITE = 'W', BLACK = 'B' };
enum POSITION_TYPE {
  NOT_DEFINE,
  INVALID,
  COMMON,
  CHECK,
  CHECKMATE,
  DRAW,
  STALEMATE
};

enum PIECE_NAME: char {
  EMPTY,
  PAWN = 'p',
  KNIGHT = 'k',
  BISHOP = 'b',
  ROOK = 'r',
  QUEEN = 'q',
  KING = 'K'
};

#endif
