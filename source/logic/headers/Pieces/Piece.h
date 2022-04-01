
#ifndef PIECE_H_
#define PIECE_H_

#include "../Enums.h"

class Move;

class Position;

class Piece {
 public:
  [[nodiscard]] virtual const Move* DefineMove(int from_row_,
                                               int from_col_,
                                               int to_row_,
                                               int to_col_,
                                               const Position& position_) const = 0;
  [[nodiscard]] virtual PIECE_NAME GetPieceName() const = 0;
  [[nodiscard]] virtual COLOR GetColor() const = 0;
};

#endif
