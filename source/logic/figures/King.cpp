//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

King::King(COLOR color_): color_(color_) {}

King* King::get_piece(COLOR color) {
    if (color == WHITE) {
        if (white_king_ == nullptr) {
            white_king_ = new King(WHITE);
        }
        return white_king_;
    }
    if (color == BLACK) {
        if (black_king_ == nullptr) {
            black_king_ = new King(BLACK);
        }
        return black_king_;
    }
    return nullptr;
}

const Move* King::define_move(int from_row_,
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
    // if King movement is incorrect
    if (std::abs(to_row_ - from_row_) != (std::abs(to_col_ - from_col_)) && (to_col_ != from_col_) && (to_row_ != from_row_)) is_correct_ = false;
    if (std::abs(to_row_ - from_row_) > 2 || std::abs(to_col_ - from_col_) > 2) is_correct_ = false;
    else {
        if (from_col_ == to_col_ && from_row_ == to_row_) is_correct_ = false;
        else if (is_correct_) {
            int diff_row_ = (to_row_ - from_row_) / (std::abs(to_row_ - from_row_) != 0 ? std::abs(to_row_ - from_row_) : 1);
            int diff_col_ = (to_col_ - from_col_) / (std::abs(to_col_ - from_col_) != 0 ? std::abs(to_col_ - from_col_) : 1);
            for (int i = 0; i < std::abs(to_row_ - from_row_); ++i) {
                if (position_.at(from_row_ + diff_row_ * i, from_col_ + diff_col_ * i)->piece_name_ != EMPTY) is_correct_ = false;
            }
        }
    }
    //check for castling
    if (position_.info_for_castle_[color_ == WHITE ? 0:3]) {
      if (to_row_ - from_row_ == 0 && std::abs(to_col_ - from_col_) == 2) {
        bool correct_castle = true;
        if (to_col_ - from_col_ == 2) {
          correct_castle = position_.info_for_castle_[color_ == WHITE ? 1:4];
          for (int i = 1; i < from_col_; ++i) {
            if (position_.at(from_row_, i)->piece_name_ != EMPTY) {
              correct_castle = false;
            }
          }
        }else {
          correct_castle = position_.info_for_castle_[color_ == WHITE ? 2:5];
          for (int i = from_col_ + 1; i < position_.board_[0].size(); ++i) {
            if (position_.at(from_row_, i)->piece_name_ != EMPTY) {
              correct_castle = false;
            }
          }
        }
        if (correct_castle) return Castle::get_move();
      }
    }
    if (is_correct_) {
        return SimpleMove::get_move();
    }
    return InvalidMove::get_move();
}