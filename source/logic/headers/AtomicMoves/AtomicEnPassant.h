
#ifndef ATOMIC_ENPASSANT_H_
#define ATOMIC_ENPASSANT_H_

#include "../Move.h"
#include <memory>

class AtomicEnPassant : public Move {
 protected:
  AtomicEnPassant();

  static std::shared_ptr<AtomicEnPassant> en_passant_move_;

 public:
  AtomicEnPassant(const AtomicEnPassant&) = delete;
  void operator=(const AtomicEnPassant&) = delete;

  static std::shared_ptr<AtomicEnPassant> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<AtomicEnPassant> AtomicEnPassant::en_passant_move_ = nullptr;

#endif
