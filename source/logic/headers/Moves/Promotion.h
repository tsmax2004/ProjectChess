
#ifndef PROMOTION_H_
#define PROMOTION_H_

#include "Move.h"

class Promotion : public Move {
 protected:
  Promotion();

  static Promotion* promotion_move_;

 public:
  Promotion(const Promotion&) = delete;
  void operator=(const Promotion&) = delete;

  static Promotion* GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline Promotion* Promotion::promotion_move_ = nullptr;

#endif
