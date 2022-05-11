
#ifndef CASTLE_H_
#define CASTLE_H_

#include "../Move.h"
#include <memory>

class Castle : public Move {
 protected:
  Castle();

  static std::shared_ptr<Castle> castle_;

 public:
  Castle(const Castle&) = delete;
  void operator=(const Castle&) = delete;

  static std::shared_ptr<Castle> GetMove();

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;
};

inline std::shared_ptr<Castle> Castle::castle_ = nullptr;

#endif
