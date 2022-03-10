//
// Created by Георгий Кузнецов on 10.03.2022.
//

#include "logic.h"

Knight::Knight(COLOR color_): color_(color_) {}

Knight* Knight::get_piece(COLOR color) {
  if (color == WHITE) {
    if (white_knight_ == nullptr) {
      white_knight_ = new Knight(WHITE);
    }
    return white_knight_;
  }
  if (color == BLACK) {
    if (black_knight_ == nullptr) {
      black_knight_ = new Knight(BLACK);
    }
    return black_knight_;
  }
}

const Move* Knight::define_move(int from_row_,
                                int from_col_,
                                int to_row_,
                                int to_col_,
                                const Position& position_) const {
  bool is_correct_ = true;
  //if move_ color is correct
  if (color_ != position_.move_color_) is_correct_ = false;
  //if move_ is made out of board borders
  if (to_row_ >= 0 && to_row_ < position_.board_.size()) is_correct_ = false;
  if (to_col_ >= 0 && to_col_ < position_.board_.size()) is_correct_ = false;
  // if move_ is made on friend square
  if (position_.at(to_row_, to_col_)->piece_name_ != EMPTY && position_.at(to_row_, to_col_)->color_ == color_)
    is_correct_ = false;
  // if knight movement is incorrect
  auto mov_ = std::pair<int, int>(std::abs(to_row_ - from_row_), std::abs(to_col_ - from_col_));
  auto cor_mov_ = std::pair<int, int>(1, 2);
  if (mov_ != cor_mov_ &&
      (mov_.first != cor_mov_.second || mov_.second != cor_mov_.first))
    is_correct_ = false;
  if (is_correct_) {
    return SimpleMove::get_move();
  }
  return InvalidMove::get_move();
}
