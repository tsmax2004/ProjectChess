//
// Created by evgen on 09.04.2022.
//

#include "headers/Logic.h"

Logic::Logic() : Game() {};

void Logic::MakeMove(int from_row, int from_col, int to_row, int to_col) {
    Game.MakeMove(from_row, from_col, to_row, to_col);
}

void Logic::StartNewGame() {
    Game.StartNewGame();
}

void Logic::CancelMove() {
    Game.CancelMove();
}

std::shared_ptr<Position> Logic::GetBoard() {
    return Game.GetPosition();
}