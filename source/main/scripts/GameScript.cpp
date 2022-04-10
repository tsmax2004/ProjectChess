#include "../headers/scripts/GameScript.h"

#include <utility>

GameScript::GameScript(GameWindow interface): game_logic_(), interface_(std::move(interface)) {}

void GameScript::Initialize(GameWindow interface) {
  instance_ = std::shared_ptr<GameScript>(new GameScript(std::move(interface)));
}

std::shared_ptr<GameScript> GameScript::Get() {
  return instance_;
}

std::shared_ptr<Script> GameScript::Run() {
  auto action = interface_.GetAction();
  if (action.action_type == GAME_ACTION_TYPE::MAKE_MOVE) {
    game_logic_.MakeMove(action.row_from, action.col_from, action.row_to, action.col_to);
  }
  if (action.action_type == GAME_ACTION_TYPE::CANCEL_MOVE) {
    game_logic_.CancelMove();
  }
  if (action.action_type == GAME_ACTION_TYPE::EXIT_TO_MENU) {
    return MenuScript::Get();
  }
  return GameScript::Get();
}
