//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Pawn::Pawn(COLOR color_) : color_(color_) {}

Pawn* Pawn::get_piece(COLOR color) {
  if (color == WHITE) {
    if (white_pawn_ == nullptr) {
      white_pawn_ = new Pawn(WHITE);
    }
    return white_pawn_;
  }
  if (color == BLACK) {
    if (black_pawn_ == nullptr) {
      black_pawn_ = new Pawn(BLACK);
    }
    return black_pawn_;
  }
  return nullptr;
}

const Move* Pawn::define_move(int from_row_,
                              int from_col_,
                              int to_row_,
                              int to_col_,
                              const Position& position_) const {
  bool is_correct_ = true;
  //if move_ color is correct
  if (color_ != position_.move_color_) is_correct_ = false;
  // if move_ is made on friend square
  if (position_.at(to_row_, to_col_)->piece_name_ != EMPTY && position_.at(to_row_, to_col_)->color_ == color_)
    is_correct_ = false;
  // if Pawn movement is incorrect
//  if (std::abs(to_row_ - from_row_) != 1 || std::abs(to_col_ - from_col_) > 1) is_correct_ = false;
  if (std::abs(to_row_ - from_row_) != (std::abs(to_col_ - from_col_)) || (to_col_ != from_col_)
      || (to_row_ != from_row_))
    is_correct_ = false;
  if ((color_ == WHITE && from_row_ != 1 && (std::abs(to_row_ - from_row_) + std::abs(to_col_ - from_col_)) > 1))
    is_correct_ = false;
  if ((color_ == WHITE && from_row_ == 1 && (std::abs(to_row_ - from_row_) + std::abs(to_col_ - from_col_)) > 2))
    is_correct_ = false;
  if ((color_ == BLACK && from_row_ != 6 && (std::abs(to_row_ - from_row_) + std::abs(to_col_ - from_col_)) > 1))
    is_correct_ = false;
  if ((color_ == BLACK && from_row_ == 6 && (std::abs(to_row_ - from_row_) + std::abs(to_col_ - from_col_)) > 2))
    is_correct_ = false;
  else {
    if (from_col_ == to_col_ && from_row_ == to_row_) is_correct_ = false;
    else if (is_correct_) {
      int diff_row_ = (to_row_ - from_row_) / (std::abs(to_row_ - from_row_) != 0 ? std::abs(to_row_ - from_row_) : 1);
      int diff_col_ = (to_col_ - from_col_) / (std::abs(to_col_ - from_col_) != 0 ? std::abs(to_col_ - from_col_) : 1);
      for (int i = 0; i < std::abs(to_row_ - from_row_); ++i) {
        if (position_.at(from_row_, from_col_)->piece_name_ != EMPTY) is_correct_ = false;
        from_row_ += diff_row_;
        from_col_ += diff_col_;
      }
    }
  }
  if (is_correct_ && to_row_ == position_.board_.size() - 1) {
    return Promotion::get_move();
  }
  if (is_correct_ && !position_.last_move_.empty()
      && (std::abs(position_.last_move_.at(0) - position_.last_move_.at(2)) == 2)) {
    if (position_.board_.at(position_.last_move_.at(2)).at(position_.last_move_.at(3))->piece_name_ == PAWN
        && (std::abs(position_.last_move_.at(2) - from_row_) + std::abs(position_.last_move_.at(3) - from_col_)) == 1) {
      return EnPassant::get_move();
    }
  } else if (is_correct_) {
    return SimpleMove::get_move();
  }
  return InvalidMove::get_move();
}