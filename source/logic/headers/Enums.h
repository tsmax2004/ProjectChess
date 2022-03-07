
#ifndef ENUMS_H_
#define ENUMS_H_

enum COLOR { WHITE, BLACK };
enum POSITION_TYPE { NOT_DEFINE,
                     COMMON,
                     CHECK_FOR_WHITE,
                     CHECK_FOR_BLACK,
                     CHECKMATE_FOR_WHITE,
                     CHECKMATE_FOR_BLACK,
                     DRAW };

enum PIECE_NAME { EMPTY,
                  PAWN,
                  KNIGHT,
                  BISHOP,
                  ROOK,
                  QUEEN,
                  KING };

#endif
