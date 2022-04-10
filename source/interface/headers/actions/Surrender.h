
#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_SURRENDERMOVE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_ACTION_ACTIONS_TYPES_SURRENDERMOVE_H_

#include "../logic_part.h"

class Surrender {
 private:
  static std::shared_ptr<Surrender> instance_;
  Surrender();
 public:
  static std::shared_ptr<Surrender> GetInstance();
  static void GetAction(const std::shared_ptr<Game>&);
};

inline std::shared_ptr<Surrender> Surrender::instance_ = nullptr;
#endif
