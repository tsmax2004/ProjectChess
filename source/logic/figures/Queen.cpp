//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Queen::Queen(COLOR color_): color_(color_) {}

Queen* Queen::get_piece(COLOR color) {
    if (color == WHITE) {
        if (white_queen_ == nullptr) {
            white_queen_ = new Queen(WHITE);
        }
        return white_queen_;
    }
    if (color == BLACK) {
        if (black_queen_ == nullptr) {
            black_queen_ = new Queen(BLACK);
        }
        return black_queen_;
    }
}

const Move* Queen::define_move(int from_row_,
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
    // if Queen movement is incorrect
    if (std::abs(to_row_ - from_row_) != (std::abs(to_col_ - from_col_)) && (to_col_ != from_col_) && (to_row_ != from_row_)) is_correct_ = false;
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
    if (is_correct_) {
        return SimpleMove::get_move();
    }
    return InvalidMove::get_move();
}