
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_GAME_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_GAME_H_

#include "../../../logic/headers/logic.h"
#include "../../../interface/headers/windows/GameWindow.h"

class Game {
 public:
  Game();
  void Run();

 private:
  GameLogic game_logic_;
  GameWindow interface_;
};

#endif
