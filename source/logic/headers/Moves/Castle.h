
#ifndef CASTLE_H_
#define CASTLE_H_

#include "Move.h"

class Castle : public Move {
 protected:
  Castle();

  static Castle* castle_;

 public:
  Castle(const Castle&) = delete;
  void operator=(const Castle&) = delete;

  static Castle* GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline Castle* Castle::castle_ = nullptr;

#endif
