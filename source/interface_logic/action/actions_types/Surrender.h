//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_SURRENDERMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_SURRENDERMOVE_H_

#include "../../logic/headers/Game.h"

class Surrender {
 private:
  static std::shared_ptr<Surrender> instance_;
  Surrender();
 public:
  static std::shared_ptr<Surrender> GetInstance();
  void GetAction(std::shared_ptr<Game>);
};

inline std::shared_ptr<Surrender> Surrender::instance_ = nullptr;
#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_SURRENDERMOVE_H_
