#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_HEAD_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_HEAD_H_

#include "actions/actions.h"
#include "../console_interface/headers/Interface.h"

class Head {
  private:
    std::shared_ptr<Interface> interface_;
    std::shared_ptr<Game> game_;
  public:
    Head();
    std::shared_ptr<Action> GetInterFaceAction();
    void MenuCycle();
    void GameCycle();
};

#endif
