#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_
#include "../../logic/headers/Game.h"
#include <string>

class CancelMove {
  private:
    std::string type_ = "Cancel Move";
    static std::shared_ptr<CancelMove> instance_;
    CancelMove();
  public:
    static std::shared_ptr<CancelMove> GetInstance();
    void GetAction(std::shared_ptr<Game>);
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_
