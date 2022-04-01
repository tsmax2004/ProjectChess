//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"
#include <cstdlib>

King::King(COLOR color_) : color_(color_) {}

King* King::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_king_ == nullptr) {
      white_king_ = new King(COLOR::WHITE);
    }
    return white_king_;
  }
  if (color == COLOR::BLACK) {
    if (black_king_ == nullptr) {
      black_king_ = new King(COLOR::BLACK);
    }
    return black_king_;
  }
  return nullptr;
}

const Move* King::DefineMove(int from_row_,
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
  // if King movement is incorrect
  if (std::abs(to_row_ - from_row_) >= 2 || std::abs(to_col_ - from_col_) >= 2) is_correct_ = false;
  if ((to_row_ == from_row_) && (to_col_ == from_col_)) is_correct_ = false;
  //check for castling
  if ((position_.info_for_castle_[color_ == COLOR::WHITE ? 0 : 3]) && (position_.position_type_ == POSITION_TYPE::COMMON)) {
    if (to_row_ - from_row_ == 0 && std::abs(to_col_ - from_col_) == 2) {
      bool correct_castle = true;
      if (to_col_ - from_col_ == 2) {
        correct_castle = position_.info_for_castle_[color_ == COLOR::WHITE ? 2 : 5];
        for (int i = from_col_ + 1; i <= to_col_; ++i) {
          if (position_.at(from_row_, i)->GetPieceName() != EMPTY)
            correct_castle = false;
          if (position_.SquareIsUnderAttack(from_row_, i, color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE))
            correct_castle = false;
        }
      } else {
        correct_castle = position_.info_for_castle_[color_ == COLOR::WHITE ? 1 : 4];
        for (int i = to_col_ - 1; i < from_col_; ++i) {
          if (position_.at(from_row_, i)->GetPieceName() != EMPTY)
            correct_castle = false;
          if ((i != to_col_ - 1)
              && (position_.SquareIsUnderAttack(from_row_, i, color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE)))
            correct_castle = false;
        }
      }
      if (correct_castle) return Castle::GetMove();
    }
  }
  if (is_correct_) {
    return SimpleMove::GetMove();
  }
  return InvalidMove::GetMove();
}

PIECE_NAME King::GetPieceName() const {
  return KING;
}
COLOR King::GetColor() const {
  return color_;
}
