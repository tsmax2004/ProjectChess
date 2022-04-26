
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_INTERFACE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_INTERFACE_H_

#include <memory>
#include "windows/windows.h"
#include "console/windows/windows.h"

class Interface {
 public:
  Interface();

  std::shared_ptr<GameWindow> GetGameInterface();
  std::shared_ptr<MenuWindow> GetMenuInterface();

 private:
  std::shared_ptr<GameWindow> game_window_;
  std::shared_ptr<MenuWindow> menu_window_;
};

#endif
