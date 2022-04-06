
#ifndef INPASSING_H_
#define INPASSING_H_

#include "Move.h"
#include <memory>

class EnPassant : public Move {
 protected:
  EnPassant();

  static std::shared_ptr<EnPassant> en_passant_move_;

 public:
  EnPassant(const EnPassant&) = delete;
  void operator=(const EnPassant&) = delete;

  static std::shared_ptr<EnPassant> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<EnPassant> EnPassant::en_passant_move_ = nullptr;

#endif
