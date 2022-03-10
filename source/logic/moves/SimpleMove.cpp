//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

SimpleMove::SimpleMove() = default;

SimpleMove* SimpleMove::get_move() {
    if (simple_move_ == nullptr) {
        return (new SimpleMove());
    }
    return simple_move_;
}

void SimpleMove::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {
    if (position.at(from_row, from_col)->piece_name_ == ROOK) {
        if (position.at(from_row, from_col)->color_ == WHITE) {
            if (from_row == 0 && from_col == 0) {
                position.info_for_castle_[1] = true;
            }
            if (from_row == 0 && from_col == 7) {
                position.info_for_castle_[2] = true;
            }
        }
        if (position.at(from_row, from_col)->color_ == BLACK) {
            if (from_row == 7 && from_col == 0) {
                position.info_for_castle_[4] = true;
            }
            if (from_row == 7 && from_col == 7) {
                position.info_for_castle_[5] = true;
            }
        }
    }
    if (position.at(from_row, from_col)->piece_name_ == KING) {
        position.info_for_castle_[(position.at(from_row, from_col)->color_ == WHITE ? 0 : 3)];
    }
    position.move_color_ = (position.at(to_row, to_col)->color_ == WHITE ? BLACK : WHITE);
    position.board_.at(to_row).at(to_col) = position.board_.at(from_row).at(from_col);
    position.at(from_row, from_col)->piece_name_ = EMPTY;
    position.at(from_row, from_col)->color_ = WHITE;
    position.last_move_ = {from_row, from_col, to_row, to_col};
    position.position_type_ = NOT_DEFINE;
};