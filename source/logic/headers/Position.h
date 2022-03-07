
#ifndef POSITION_H_
#define POSITION_H_

#include <vector>
#include "Pieces/Piece.h"
#include "Enums.h"

class Position {
public:
    Position();

    Position(const Position &);

    void start_position();

    Piece *at(int row, int col) const;

    std::vector<Piece *> board_;
    COLOR move_color_;
    POSITION_TYPE position_type_ = NOT_DEFINE;

    std::vector<bool> info_for_castle_;
    // info about figures movement in order: WhiteKing, WhiteRookA, WhiteRookH, BlackKing, BlackRookA, BlackRookH
    std::vector<int> last_move;

    // for in passing, in order from_row, from_col, to_row, to_col
    void define_position_type() const;

private:

    bool if_check() const;

    bool if_checkmate() const;

    bool if_draw() const;

    bool if_stalemate() const;
};

#endif
