//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Empty::Empty() = default;

Empty* Empty::GetPiece() {
  if (empty_ == nullptr)
    empty_ = new Empty();
  return empty_;
}

const Move* Empty::DefineMove(int from_row_, int from_col_, int to_row_, int to_col_,
                              const Position& position_) const {
  return InvalidMove::GetMove();
}

PIECE_NAME Empty::GetPieceName() const {
  return EMPTY;
}
COLOR Empty::GetColor() const {
  return COLOR::WHITE;
}
