
#ifndef ATOMIC_SIMPLEMOVE_H_
#define ATOMIC_SIMPLEMOVE_H_

#include "../Move.h"
#include <memory>

class AtomicSimpleMove : public Move {
 protected:
  AtomicSimpleMove();

  static std::shared_ptr<AtomicSimpleMove> simple_move_;

 public:
  AtomicSimpleMove(const AtomicSimpleMove&) = delete;
  void operator=(const AtomicSimpleMove&) = delete;

  static std::shared_ptr<AtomicSimpleMove> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<AtomicSimpleMove> AtomicSimpleMove::simple_move_ = nullptr;

#endif
