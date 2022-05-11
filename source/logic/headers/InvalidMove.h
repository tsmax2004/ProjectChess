
#ifndef InvalidMove_H_
#define InvalidMove_H_

#include "Move.h"
#include <memory>

class InvalidMove : public Move {
 protected:
  InvalidMove();

  static std::shared_ptr<InvalidMove> invalid_move_;

 public:
  InvalidMove(const InvalidMove&) = delete;
  void operator=(const InvalidMove&) = delete;

  static std::shared_ptr<InvalidMove> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<InvalidMove> InvalidMove::invalid_move_ = nullptr;

#endif
