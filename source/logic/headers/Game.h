
#ifndef GAME_H_
#define GAME_H_

#include "Position.h"
#include "moves.h"
#include <vector>
#include <memory>

class Game {
 protected:
  std::shared_ptr<Position> position_;
  std::vector<std::shared_ptr<Position>> position_history_;

 public:
  Game();
  void StartNewGame();

  void GameCycle();

  [[nodiscard]] bool CheckForRepeating() const;

  void PrintBoard() const;
  [[nodiscard]] std::shared_ptr<Position> return_position() const;
};

#endif
