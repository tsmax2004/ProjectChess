
#ifndef SIMPLEMOVE_H_
#define SIMPLEMOVE_H_

#include "../Move.h"
#include <memory>

class SimpleMove : public Move {
 protected:
  SimpleMove();

  static std::shared_ptr<SimpleMove> simple_move_;

 public:
  SimpleMove(const SimpleMove&) = delete;
  void operator=(const SimpleMove&) = delete;

  static std::shared_ptr<SimpleMove> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<SimpleMove> SimpleMove::simple_move_ = nullptr;

#endif
