//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Empty::Empty() = default;

Empty* Empty::get_piece() {
  if (empty_ == nullptr)
    empty_ = new Empty();
  return empty_;
}

const Move* Empty::define_move(int from_row_, int from_col_, int to_row_, int to_col_,
                               const Position& position_) const {
  return InvalidMove::get_move();
}

PIECE_NAME Empty::get_piece_name() const {
  return EMPTY;
}
COLOR Empty::get_color() const {
  return WHITE;
}
