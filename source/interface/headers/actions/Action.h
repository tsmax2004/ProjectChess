
#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTIONS_ACTION_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTIONS_ACTION_H_

#include <string>
#include "../logic_part.h"

class Action {
  private:
    std::string type_;
  public:
    void virtual GetAction(Game*) = 0;
};

#endif
