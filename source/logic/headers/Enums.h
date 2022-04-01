
#ifndef ENUMS_H_
#define ENUMS_H_

enum class COLOR: char { WHITE = 'W', BLACK = 'B' };
enum class POSITION_TYPE {
  NOT_DEFINED,
  INVALID,
  COMMON,
  CHECK,
  CHECKMATE,
  DRAW
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
