
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_INTERFACE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_INTERFACE_H_

#include "windows/windows.h"
#include <memory>

class Interface {
 public:
  Interface();

  GameWindow GetGameInterface();
  MenuWindow GetMenuInterface();

 private:
  GameWindow game_window_;
  MenuWindow menu_window_;
};

#endif
