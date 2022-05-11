
#ifndef PIECE_H_
#define PIECE_H_

#include "Enums.h"
#include <memory>

class Move;

class Position;

class Piece {
 public:
  explicit Piece(COLOR);

  [[nodiscard]] virtual std::shared_ptr<Move> DefineMove(int from_row_,
                                                         int from_col_,
                                                         int to_row_,
                                                         int to_col_,
                                                         const Position& position_) const = 0;
  [[nodiscard]] virtual PIECE_NAME GetPieceName() const = 0;
  [[nodiscard]] COLOR GetColor() const;

 protected:
  [[nodiscard]] bool CheckMoveColor(const Position& position) const;
  [[nodiscard]] bool CheckAttackSquareIsNotFriend(int to_row, int to_col, const Position& position) const;
  [[nodiscard]] static bool CheckBetweenSquaresAreEmpty(int from_row,
                                                        int from_col,
                                                        int to_row,
                                                        int to_col,
                                                        const Position& position);

  COLOR color_;
};

#endif
