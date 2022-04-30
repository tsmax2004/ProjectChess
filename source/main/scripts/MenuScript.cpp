#include "../headers/scripts/scripts.h"
#include "../../configs.h"

MenuScript::MenuScript(std::shared_ptr<MenuWindow> interface) : interface_(std::move(interface)) {}

void MenuScript::Initialize(std::shared_ptr<MenuWindow> interface) {
  if (!instance_) {
    instance_ = std::shared_ptr<MenuScript>(new MenuScript(std::move(interface)));
  }
}

std::shared_ptr<MenuScript> MenuScript::Get() {
  return instance_;
}

std::shared_ptr<Script> MenuScript::Run() {
  interface_->DrawMenuWindow();

  while (true) {
    auto action = interface_->GetAction();
    if (action.action_type == MENU_ACTION_TYPE::NEW_GAME) { return GameScript::Get(); }
    if (action.action_type == MENU_ACTION_TYPE::CHANGE_MODE) { GAME_MODE = action.mode; }
    if (action.action_type == MENU_ACTION_TYPE::EXIT) { return ExitScript::Get(); }
  }
}