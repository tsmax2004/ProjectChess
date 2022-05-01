
#ifndef PROMOTION_H_
#define PROMOTION_H_

#include "../Move.h"
#include <memory>

class Promotion : public Move {
 protected:
  Promotion();

  static std::shared_ptr<Promotion> promotion_move_;

 public:
  Promotion(const Promotion&) = delete;
  void operator=(const Promotion&) = delete;

  static std::shared_ptr<Promotion> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<Promotion> Promotion::promotion_move_ = nullptr;

#endif
