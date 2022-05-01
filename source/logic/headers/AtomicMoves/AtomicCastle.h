
#ifndef ATOMIC_CASTLE_H_
#define ATOMIC_CASTLE_H_

#include "../Move.h"
#include <memory>

class AtomicCastle : public Move {
 protected:
  AtomicCastle();

  static std::shared_ptr<AtomicCastle> castle_;

 public:
  AtomicCastle(const AtomicCastle&) = delete;
  void operator=(const AtomicCastle&) = delete;

  static std::shared_ptr<AtomicCastle> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<AtomicCastle> AtomicCastle::castle_ = nullptr;

#endif
