
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_MAIN_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_MAIN_H_

#include "scripts/scripts.h"
#include "../../interface/headers/Interface.h"

class Main {
 public:
  Main();
  void RunMenu();
  void RunGame();

 private:
  Game game_script;
  Menu menu_script;

  Interface interface_;
};

#endif
