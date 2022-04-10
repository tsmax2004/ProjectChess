#include "../headers/scripts/scripts.h"

MenuScript::MenuScript(MenuWindow interface) : interface_(interface) {}

void MenuScript::Initialize(MenuWindow interface) {
  instance_ = std::shared_ptr<MenuScript>(new MenuScript(interface));
}

std::shared_ptr<MenuScript> MenuScript::Get() {
  return instance_;
}

std::shared_ptr<Script> MenuScript::Run() {
  interface_.DrawMenuWindow();
  auto action = interface_.GetAction();
  if (action.action_type == MENU_ACTION_TYPE::NEW_GAME) { return GameScript::Get(); }
  if (action.action_type == MENU_ACTION_TYPE::EXIT) { return ExitScript::Get(); }
  return nullptr;
}