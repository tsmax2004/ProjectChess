
#ifndef GAME_H_
#define GAME_H_

#include "Position.h"
#include "moves.h"
#include <vector>

class Game {
 protected:
  Position* position_;
  std::vector<Position*> position_history_;

 public:
  Game();
  void StartNewGame();

  void GameCycle();

  [[nodiscard]] bool CheckForRepeating() const;

  void PrintBoard() const;
};

#endif
