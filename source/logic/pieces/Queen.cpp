//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"
#include <cstdlib>

Queen::Queen(COLOR color_) : color_(color_) {}

Queen* Queen::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_queen_ == nullptr) {
      white_queen_ = new Queen(COLOR::WHITE);
    }
    return white_queen_;
  }
  if (color == COLOR::BLACK) {
    if (black_queen_ == nullptr) {
      black_queen_ = new Queen(COLOR::BLACK);
    }
    return black_queen_;
  }
  return nullptr;
}

const Move* Queen::DefineMove(int from_row_,
                              int from_col_,
                              int to_row_,
                              int to_col_,
                              const Position& position_) const {
  bool is_correct_ = true;
  //if move_ color is correct
  if (color_ != position_.move_color_) is_correct_ = false;
  // if move_ is made on friend square
  if (position_.at(to_row_, to_col_)->GetPieceName() != EMPTY
      && position_.at(to_row_, to_col_)->GetColor() == color_)
    is_correct_ = false;
  // if Queen movement is incorrect
  if (std::abs(to_row_ - from_row_) != (std::abs(to_col_ - from_col_)) && (to_col_ != from_col_)
      && (to_row_ != from_row_))
    is_correct_ = false;
  else {
    if (from_col_ == to_col_ && from_row_ == to_row_) is_correct_ = false;
    else if (is_correct_) {
      int diff_row_ = (to_row_ - from_row_) / (std::abs(to_row_ - from_row_) != 0 ? std::abs(to_row_ - from_row_) : 1);
      int diff_col_ = (to_col_ - from_col_) / (std::abs(to_col_ - from_col_) != 0 ? std::abs(to_col_ - from_col_) : 1);
      for (int i = 1; i < std::max(std::abs(to_row_ - from_row_), std::abs(to_col_ - from_col_)); ++i) {
        if (position_.at(from_row_ + i * diff_row_, from_col_ + i * diff_col_)->GetPieceName() != EMPTY)
          is_correct_ = false;
      }
    }
  }
  if (is_correct_) {
    return SimpleMove::GetMove();
  }
  return InvalidMove::GetMove();
}

PIECE_NAME Queen::GetPieceName() const {
  return QUEEN;
}
COLOR Queen::GetColor() const {
  return color_;
}
