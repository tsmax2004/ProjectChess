//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

SimpleMove::SimpleMove() = default;

SimpleMove* SimpleMove::get_move() {
  if (simple_move_ == nullptr) {
    return (new SimpleMove());
  }
  return simple_move_;
}

void SimpleMove::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  if (position.at(from_row, from_col)->get_piece_name() == ROOK) {
    if (position.at(from_row, from_col)->get_color() == WHITE) {
      if (from_row == 0 && from_col == 0) {
        position.info_for_castle_[1] = false;
      }
      if (from_row == 0 && from_col == position.board_[0].size() - 1) {
        position.info_for_castle_[2] = false;
      }
    }
    if (position.at(from_row, from_col)->get_color() == BLACK) {
      if (from_row == position.board_.size() - 1 && from_col == 0) {
        position.info_for_castle_[4] = false;
      }
      if (from_row == position.board_.size() - 1 && from_col == position.board_[0].size() - 1) {
        position.info_for_castle_[5] = false;
      }
    }
  }
  if (position.at(from_row, from_col)->get_piece_name() == KING) {
    position.info_for_castle_[(position.at(from_row, from_col)->get_color() == WHITE ? 0 : 3)] = false;
  }
  position.move_color_ = (position.move_color_ == WHITE ? BLACK : WHITE);
  position.board_[to_row][to_col] = position.at(from_row, from_col);
  position.board_[from_row][from_col] = Empty::get_piece();
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.position_type_ = NOT_DEFINE;
};

bool SimpleMove::is_valid() const {
  return true;
}
