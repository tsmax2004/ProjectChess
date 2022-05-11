
#ifndef ATOMIC_PROMOTION_H_
#define ATOMIC_PROMOTION_H_

#include "../Move.h"
#include <memory>

class AtomicPromotion : public Move {
 protected:
  AtomicPromotion();

  static std::shared_ptr<AtomicPromotion> promotion_move_;

 public:
  AtomicPromotion(const AtomicPromotion&) = delete;
  void operator=(const AtomicPromotion&) = delete;

  static std::shared_ptr<AtomicPromotion> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<AtomicPromotion> AtomicPromotion::promotion_move_ = nullptr;

#endif
