
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_GAMESCRIPT_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_GAMESCRIPT_H_

#include "scripts.h"
#include "../../../logic/headers/logic.h"
#include "../../../interface/headers/windows/GameWindow.h"

#include <memory>

class GameScript: public Script {
 public:
  static std::shared_ptr<GameScript> Get();
  static void Initialize(GameWindow);

  std::shared_ptr<Script> Run() override;

 private:
  static std::shared_ptr<GameScript> instance_;

  explicit GameScript(GameWindow);
  GameLogic game_logic_;
  GameWindow interface_;

  std::shared_ptr<Script> to_return;  // flag - to break cycle
};

inline std::shared_ptr<GameScript> GameScript::instance_ = nullptr;

#endif
