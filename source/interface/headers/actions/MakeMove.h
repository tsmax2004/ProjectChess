//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_MAKEMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_MAKEMOVE_H_

#include "../logic_part.h"

class MakeMove {
 private:
  static std::shared_ptr<MakeMove> instance_;
  static std::pair<int, int> from_square_;
  static std::pair<int, int> to_square_;
  MakeMove(int, int, int, int);
 public:
  static std::shared_ptr<MakeMove> GetInstance(int, int, int, int);
  static void GetAction(const std::shared_ptr<Game>&);
};

inline std::shared_ptr<MakeMove> MakeMove::instance_ = nullptr;
#endif
