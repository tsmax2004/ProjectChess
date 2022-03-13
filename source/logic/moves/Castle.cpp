//
// Created by Георгий Кузнецов on 11.03.2022.
//

#include "../headers/logic.h"
Castle::Castle() = default;
Castle* Castle::get_move() {
  if (castle_ == nullptr) {
    castle_ = new Castle();
  }
  return castle_;
}
void Castle::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.info_for_castle_[position.at(from_row, from_col)->get_color() == WHITE ? 0 : 3] = false;
  if (from_col - to_col > 0) {
    position.board_[from_row][from_col - 1] = position.at(from_row, 0);
    position.board_[from_row][0] = Empty::get_piece();
  } else {
    position.board_[from_row][from_col + 1] = position.at(from_row, position.board_[0].size() - 1);
    position.board_[to_row][position.board_[0].size() - 1] = Empty::get_piece();
  }
  position.board_[to_row][to_col] = position.at(from_row, from_col);
  position.board_[from_row][from_col] = Empty::get_piece();
  position.move_color_ = (position.move_color_ == WHITE ? BLACK : WHITE);
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.position_type_ = NOT_DEFINE;
}

bool Castle::is_valid() const {
  return true;
}
