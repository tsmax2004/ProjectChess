//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_MAKEMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_MAKEMOVE_H_

#include "../../logic/headers/Game.h"

class MakeMove {
 private:
  static std::shared_ptr<MakeMove> instance_;
  static std::pair<int, int> from_square_;
  static std::pair<int, int> to_square_;
  MakeMove(int, int, int, int);
 public:
  static std::shared_ptr<MakeMove> GetInstance(int, int, int, int);
  void GetAction(std::shared_ptr<Game>);
};

inline std::shared_ptr<MakeMove> MakeMove::instance_ = nullptr;
#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_MAKEMOVE_H_
