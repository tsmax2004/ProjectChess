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
}

const Move* Rook::define_move(int from_row_,
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
    // if Rook movement is incorrect
    if ((to_col_ != from_col_) && (to_row_ != from_row_)) is_correct_ = false;
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
    bool flag = false;
    if (is_correct_ && ((to_row_ == 0 && to_col_ == 3) || (to_row_ == 0 && to_col_ == 5) || (to_row_ == 7 && to_col_ == 3) || (to_row_ == 7 && to_col_ == 5))) {
        if (color_ == WHITE && Position::info_for_castle_.at(0) == false &&
        (from_row_ == 0 && from_col_ == 0 ? Position::info_for_castle_.at(1) == false : Position::info_for_castle_.at(2) == false)) {
            bool flag = true;
            return  Castle::get_move();
        }
        if (color_ == BLACK && Position::info_for_castle_.at(3) == false &&
            (from_row_ == 7 && from_col_ == 7 ? Position::info_for_castle_.at(4) == false : Position::info_for_castle_.at(5) == false)) {
            bool flag = true;
            return  Castle::get_move();
        }
    }
    else if (is_correct_ && !flag) {
        return SimpleMove::get_move();
    }
    return InvalidMove::get_move();
}