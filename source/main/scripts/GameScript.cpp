#include "../headers/scripts/GameScript.h"

GameScript::GameScript(GameWindow interface): game_logic_(), interface_(interface) {}

void GameScript::Initialize(GameWindow interface) {
  instance_ = std::shared_ptr<GameScript>(new GameScript(interface));
}

std::shared_ptr<GameScript> GameScript::Get() {
  return instance_;
}

std::shared_ptr<Script> GameScript::Run() {
  return ExitScript::Get();
}
