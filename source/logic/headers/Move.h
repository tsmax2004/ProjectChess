
#ifndef MOVE_H_
#define MOVE_H_

#include "Enums.h"

class Position;

class Move {
 public:
  virtual void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const = 0;
  [[nodiscard]] virtual bool IsValid() const = 0;
};

#endif
