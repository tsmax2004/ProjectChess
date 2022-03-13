//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Rook::Rook(COLOR color_): color_(color_) {}

Rook* Rook::get_piece(COLOR color) {
    if (color == WHITE) {
        if (white_rook_ == nullptr) {
            white_rook_ = new Rook(WHITE);
        }
        return white_rook_;
    }
    if (color == BLACK) {
        if (black_rook_ == nullptr) {
            black_rook_ = new Rook(BLACK);
        }
        return black_rook_;
    }
  return nullptr;
}

const Move* Rook::define_move(int from_row_,
                               int from_col_,
                               int to_row_,
                               int to_col_,
                               const Position& position_) const {
    bool is_correct_ = true;
    //if move_ color is correct
    if (color_ != position_.move_color_) is_correct_ = false;
    // if move_ is made on friend square
    if (position_.at(to_row_, to_col_)->get_piece_name() != EMPTY && position_.at(to_row_, to_col_)->get_color() == color_)
        is_correct_ = false;
    // if Rook movement is incorrect
    if ((to_col_ != from_col_) && (to_row_ != from_row_)) is_correct_ = false;
    else {
        if (from_col_ == to_col_ && from_row_ == to_row_) is_correct_ = false;
        else if (is_correct_) {
            int diff_row_ = (to_row_ - from_row_) / (std::abs(to_row_ - from_row_) != 0 ? std::abs(to_row_ - from_row_) : 1);
            int diff_col_ = (to_col_ - from_col_) / (std::abs(to_col_ - from_col_) != 0 ? std::abs(to_col_ - from_col_) : 1);
            for (int i = 1; i < std::max(std::abs(to_row_ - from_row_), std::abs(to_col_ - from_col_)); ++i) {
                if (position_.at(from_row_ + diff_row_ * i, from_col_ + diff_col_ * i)->get_piece_name() != EMPTY) is_correct_ = false;
            }
        }
    }

    if (is_correct_) {
        return SimpleMove::get_move();
    }
    return InvalidMove::get_move();
}

PIECE_NAME Rook::get_piece_name() const {
  return ROOK;
}
COLOR Rook::get_color() const {
  return color_;
}
