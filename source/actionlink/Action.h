//
// Created by Георгий Кузнецов on 10.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_ACTIONLINK_ACTION_H_
#define CHESSPROJECT_SOURCE_ACTIONLINK_ACTION_H_

class Action {
 public:
  static void CreateMakeMoveAction(int, int, int, int) {}
 private:
  class MakeMoveAction {};
  class CancelMoveAction {};
  class SurrenderAction {};
  static MakeMoveAction make_move_action_;
  static CancelMoveAction cancel_move_action_;
  static SurrenderAction surrender_action_;
};

#endif //CHESSPROJECT_SOURCE_ACTIONLINK_ACTION_H_
