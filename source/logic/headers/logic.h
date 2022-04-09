//
// Created by evgen on 09.04.2022.
//
#include "Game.h"

class Logic {
  protected:
    Game Game;
  public:
    Logic();
    void MakeMove(int, int, int, int);
    void StartNewGame();
    void CancelMove();
    std::shared_ptr<Position> GetBoard();
    void Surrender();
    bool OfferDraw();
};