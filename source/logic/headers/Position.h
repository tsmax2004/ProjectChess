
#ifndef POSITION_H_
#define POSITION_H_

#include <vector>
#include "pieces.h"
#include "Enums.h"

class Position {
 public:
  Position();

  Position(const Position&);

  bool operator==(const Position&) const;

  void start_position();

  Piece* at(int row_, int col_) const;

  std::vector<std::vector<Piece*> > board_;
  COLOR move_color_;
  POSITION_TYPE position_type_ = NOT_DEFINE;

  std::vector<bool> info_for_castle_;
  // info about figures movement in order: WhiteKing, WhiteRookA, WhiteRookH, BlackKing, BlackRookA, BlackRookH
  std::vector<int> last_move_;
  // for in passing, in order from_row, from_col, to_row, to_col
  int move_cnt_;

  void define_position_type();

 private:
  bool if_check(COLOR color) const;
  bool if_checkmate(COLOR color) const;
  bool if_draw(COLOR color) const;
  bool if_stalemate(COLOR color) const;
};

#endif
