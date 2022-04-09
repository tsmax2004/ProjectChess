
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

  [[nodiscard]] bool CheckForRepeating() const;

 public:
  Game();
  void StartNewGame();
  bool MakeMove(int, int, int, int);
  bool CancelMove();
  bool MakeDraw();
  void Surrender();
  [[nodiscard]] const std::vector<std::vector<std::shared_ptr<Piece>>>& WhatBoard() const;
  [[nodiscard]] POSITION_TYPE WhatPositionType() const;
  [[nodiscard]] COLOR WhatColor() const;
  bool SetPosition(const std::vector<std::vector<std::shared_ptr<Piece>>>&, COLOR);
  std::shared_ptr<Position> GetPosition();
};

#endif
