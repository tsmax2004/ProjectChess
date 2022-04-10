#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_

#include "../../logic/headers/Game.h"

class CancelMove {
  private:
    static std::shared_ptr<CancelMove> instance_;
    CancelMove();
  public:
    static std::shared_ptr<CancelMove> GetInstance();
    void GetAction(std::shared_ptr<Game>);
};

inline std::shared_ptr<CancelMove> CancelMove::instance_ = nullptr;
#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_CANCELMOVE_H_
