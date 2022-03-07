
#ifndef PROJECTCHESS_SOURCE_LOGIC_HEADERS_PIECE_H_
#define PROJECTCHESS_SOURCE_LOGIC_HEADERS_PIECE_H_

#include "../Moves/Move.h"
#include "../Position.h"
#include "../Enums.h"

class Piece {
 public:
  COLOR color;
  virtual const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) = 0;
};

#endif //PROJECTCHESS_SOURCE_LOGIC_HEADERS_PIECE_H_
