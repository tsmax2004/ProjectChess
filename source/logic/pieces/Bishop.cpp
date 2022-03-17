//
// Created by Георгий Кузнецов on 10.03.2022.
//

#include "../headers/logic.h"

Bishop::Bishop(COLOR color_) : color_(color_) {}

Bishop* Bishop::get_piece(COLOR color) {
  if (color == WHITE) {
    if (white_bishop_ == nullptr) {
      white_bishop_ = new Bishop(WHITE);
    }
    return white_bishop_;
  }
  if (color == BLACK) {
    if (black_bishop_ == nullptr) {
      black_bishop_ = new Bishop(BLACK);
    }
    return black_bishop_;
  }
  return nullptr;
}

const Move* Bishop::define_move(int from_row_,
                                int from_col_,
                                int to_row_,
                                int to_col_,
                                const Position& position_) const {
  bool is_correct_ = true;
  //if move_ color is correct
  if (color_ != position_.move_color_) is_correct_ = false;
  // if move_ is made on friend square
  if (position_.at(to_row_, to_col_)->get_piece_name() != EMPTY
      && position_.at(to_row_, to_col_)->get_color() == color_)
    is_correct_ = false;
  // if bishop movement is incorrect
  if (std::abs(to_row_ - from_row_) != std::abs(to_col_ - from_col_)) is_correct_ = false;
  else {
    if ((to_row_ - from_row_) == 0) is_correct_ = false;
    else if (is_correct_) {
      int diff_row_ = (to_row_ - from_row_) / std::abs(to_row_ - from_row_);
      int diff_col_ = (to_col_ - from_col_) / std::abs(to_col_ - from_col_);
      for (int i = 1; i < std::abs(to_row_ - from_row_); ++i) {
        if (position_.at(from_row_ + i * diff_row_, from_col_ + i * diff_col_)->get_piece_name() != EMPTY)
          is_correct_ = false;
      }
    }
  }
  if (is_correct_) {
    return SimpleMove::get_move();
  }
  return InvalidMove::get_move();
}

PIECE_NAME Bishop::get_piece_name() const {
  return BISHOP;
}
COLOR Bishop::get_color() const {
  return color_;
}
