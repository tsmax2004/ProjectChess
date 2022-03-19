//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"
#include <cstdlib>

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
  if (position_.at(to_row_, to_col_)->get_piece_name() != EMPTY
      && position_.at(to_row_, to_col_)->get_color() == color_)
    is_correct_ = false;

  // if Pawn movement is incorrect
  if ((std::abs(from_col_ - to_col_) > 1) || (std::abs(from_row_ - to_row_) > 2))
    is_correct_ = false;
  if ((color_ == WHITE) && (to_row_ - from_row_ <= 0)) is_correct_ = false;
  if ((color_ == BLACK) && (to_row_ - from_row_ >= 0)) is_correct_ = false;
  if (std::abs(to_row_ - from_row_) == 2) {
    if (to_col_ != from_col_) is_correct_ = false;
    if (from_row_ != (color_ == WHITE ? 1 : 6)) is_correct_ = false;
    int diff_row = (to_row_ - from_row_) / 2;
    for (int i = 1; i <= 2; ++i) {
      if (position_.at(from_row_ + i * diff_row, from_col_)->get_piece_name() != EMPTY)
        is_correct_ = false;
    }
  }
  if (std::abs(to_row_ - from_row_) == 1) {
    if (from_col_ == to_col_) {
      if (position_.at(to_row_, to_col_)->get_piece_name() != EMPTY) is_correct_ = false;
    } else {
      if (position_.at(to_row_, to_col_)->get_piece_name() == EMPTY) {
        if (position_.last_move_.empty()) {
          is_correct_ = false;
        } else {
          auto last_move = position_.last_move_;
          if (color_ == WHITE) {
            std::vector<int> correct_last_move = {to_row_ + 1, to_col_, to_row_ - 1, to_col_};
            if ((last_move != correct_last_move)
                || (position_.at(to_row_ - 1, to_col_) != Pawn::get_piece(BLACK))) {
              is_correct_ = false;
            } else {
              return EnPassant::get_move();
            }
          } else {
            std::vector<int> correct_last_move = {to_row_ - 1, to_col_, to_row_ + 1, to_col_};
            if ((last_move != correct_last_move)
                || (position_.at(to_row_ + 1, to_col_) != Pawn::get_piece(WHITE))) {
              is_correct_ = false;
            } else {
              return EnPassant::get_move();
            }
          }
        }
      }
    }
  }

  if (is_correct_) {
    if (to_row_ == 0 || to_row_ == 7)
      return Promotion::get_move();
    return SimpleMove::get_move();
  }
  return InvalidMove::get_move();
}

PIECE_NAME Pawn::get_piece_name() const {
  return PAWN;
}
COLOR Pawn::get_color() const {
  return color_;
}
