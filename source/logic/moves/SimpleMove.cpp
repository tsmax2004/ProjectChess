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
    position.board_.at(to_row).at(to_col) = position.board_.at(from_row).at(from_col);
    position.board_.at(from_row).at(from_col)->piece_name_ = EMPTY;
    position.board_.at(from_row).at(from_col)->color_ = WHITE;
};