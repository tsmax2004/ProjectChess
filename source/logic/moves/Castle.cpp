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
  COLOR king_color_ = position.at(from_row, from_col)->get_color();
  position.info_for_castle_[king_color_ == WHITE ? 0 : 3] = false;
  if (from_col - to_col > 0) {
    position.board_[to_row][0] = Empty::get_piece();
    position.board_[from_row][from_col - 1] = Rook::get_piece(king_color_);
  } else {
    position.board_[to_row][position.board_[0].size() - 1] = Empty::get_piece();
    position.board_[from_row][from_col + 1] = Rook::get_piece(king_color_);
  }
  position.board_[from_row][from_col] = Empty::get_piece();
  position.board_.at(to_row).at(to_col) = position.board_.at(from_row).at(from_col);
  position.move_color_ = (position.at(to_row, to_col)->get_color() == WHITE ? BLACK : WHITE);
  position.last_move_ = {from_row, from_col, to_row, to_col};
}