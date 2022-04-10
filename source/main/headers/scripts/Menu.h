
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_MENU_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_MENU_H_

#include "../../../interface/headers/windows/MenuWindow.h"

class Menu {
 public:
  Menu();
  void Run();

 private:
  MenuWindow interface_;
};

#endif
