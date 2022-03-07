//
// Created by Max on 07.03.2022.
//

#ifndef PROJECTCHESS_SOURCE_LOGIC_HEADERS_GAME_H_
#define PROJECTCHESS_SOURCE_LOGIC_HEADERS_GAME_H_

#include "Enums.h"
#include "Pieces/Piece.h"
#include "Position.h"
#include <vector>

class Game {
protected:
    Position *position_;
    std::vector<Position *> position_history_;
public:
    Game();

    void create_game();

    void move(int from_row_, int from_col_, int to_row_, int to_col_);

    Position *create_new_position(const Move &);

    bool check_for_repeating();

    ~Game();
};


#endif //PROJECTCHESS_SOURCE_LOGIC_HEADERS_GAME_H_
