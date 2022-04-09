#include <string>
#include "../../logic/headers/Game.h"
#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTIONS_ACTION_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTIONS_ACTION_H_

class Action {
  private:
    std::string type_;
  public:
    void virtual GetAction(Game*);
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTIONS_ACTION_H_
