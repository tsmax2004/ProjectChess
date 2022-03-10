//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

Empty::Empty() = default;

Empty* Empty::get_piece(COLOR color) {
    return (new Empty());
}

const Move* Empty::define_move(int from_row_, int from_col_, int to_row_, int to_col_,
                               const Position &position_) const {
    return InvalidMove::get_move();
}