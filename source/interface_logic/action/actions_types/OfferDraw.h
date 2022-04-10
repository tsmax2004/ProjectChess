//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_OFFERDRAW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_OFFERDRAW_H_

#include "../../logic/headers/Game.h"

class MakeDraw {
 private:
  static std::shared_ptr<MakeDraw> instance_;
  MakeDraw();
 public:
  static std::shared_ptr<MakeDraw> GetInstance();
  void GetAction(std::shared_ptr<Game>);
};

inline std::shared_ptr<MakeDraw> MakeDraw::instance_ = nullptr;
#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_OFFERDRAW_H_
