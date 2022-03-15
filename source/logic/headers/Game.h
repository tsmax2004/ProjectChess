
#ifndef GAME_H_
#define GAME_H_

#include "Position.h"
#include "moves.h"
#include <vector>

class Game {
 protected:
  Position* position_;
  std::vector<Position*> position_history_;

 public:
  Game();
  void start_new_game();

  void game_cycle();

  bool check_for_repeating() const;

  void print_board() const;

  Position* return_position() const;
};

#endif
