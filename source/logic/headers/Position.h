
#ifndef POSITION_H_
#define POSITION_H_

#include <vector>
#include <memory>
#include <fstream>
#include "pieces.h"
#include "Enums.h"

class Position {
 public:
  Position();

  Position(const Position&);

  void SetStartPosition();
  void SetBoard(std::ifstream&);

  [[nodiscard]] std::shared_ptr<Piece> at(int row_, int col_) const;

  std::vector<std::vector<std::shared_ptr<Piece>>> board_;
  COLOR move_color_;
  POSITION_TYPE position_type_ = POSITION_TYPE::NOT_DEFINED;

  std::vector<bool> info_for_castle_;
  // info about figures movement in order: WhiteKing, WhiteRookA, WhiteRookH, BlackKing, BlackRookA, BlackRookH
  std::vector<int> last_move_;
  // for en' passant, in order from_row, from_col, to_row, to_col

  int cnt_rows = 8;
  int cnt_cols = 8;

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
