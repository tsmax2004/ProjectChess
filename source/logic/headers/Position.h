
#ifndef POSITION_H_
#define POSITION_H_

#include <vector>
#include "pieces.h"
#include "Enums.h"

class Position {
 public:
  Position();

  Position(const Position&);

  void StartPosition();

  [[nodiscard]] Piece* at(int row_, int col_) const;

  std::vector<std::vector<Piece*> > board_;
  COLOR move_color_;
  POSITION_TYPE position_type_ = POSITION_TYPE::NOT_DEFINED;

  std::vector<bool> info_for_castle_;
  // info about figures movement in order: WhiteKing, WhiteRookA, WhiteRookH, BlackKing, BlackRookA, BlackRookH
  std::vector<int> last_move_;
  // for en' passant, in order from_row, from_col, to_row, to_col

  void DefinePositionType();
  [[nodiscard]] bool SquareIsUnderAttack(int row, int col, COLOR attack_color) const;

 private:
  [[nodiscard]] bool Check(COLOR attack_color) const;
  [[nodiscard]] bool Checkmate(COLOR attack_color) const;
  [[nodiscard]] bool Draw() const;
  [[nodiscard]] bool Stalemate() const;
  [[nodiscard]] std::vector<int> FindKing(COLOR attack_color) const;
};

#endif
