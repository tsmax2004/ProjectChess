
#ifndef ENUMS_H_
#define ENUMS_H_

enum class COLOR : char { WHITE, BLACK};
enum class POSITION_TYPE {
  NOT_DEFINED,
  INVALID,
  COMMON,
  CHECK,
  CHECKMATE,
  DRAW
};

enum class PIECE_NAME : char {
  EMPTY,
  PAWN,
  KNIGHT,
  BISHOP,
  ROOK,
  QUEEN,
  KING
};

enum class ERROR_TYPE : char {
    EMPTY,
    CANCEL_MOVE,
    INCORRECT_MOVE,
    REJECT_DRAW
};

#endif
