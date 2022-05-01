//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_CRAZYMOVES_EXPLODE_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_CRAZYMOVES_EXPLODE_H_

#include <utility>

#include "../ClassicalMoves/Move.h"
class ExplodeMove : public Move {
 protected:
  ExplodeMove();
  static std::shared_ptr<Move> move_;
  static std::shared_ptr<ExplodeMove> move_ref_;

 public:
  ExplodeMove(const ExplodeMove&) = delete;
  void operator=(const ExplodeMove&) = delete;

  static std::shared_ptr<ExplodeMove> GetMove(std::shared_ptr<Move>);

  void MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  [[nodiscard]] bool IsValid() const override;

};

inline std::shared_ptr<ExplodeMove> ExplodeMove::move_ref_ = nullptr;
inline std::shared_ptr<Move> ExplodeMove::move_ = nullptr;
#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_CRAZYMOVES_EXPLODE_H_
