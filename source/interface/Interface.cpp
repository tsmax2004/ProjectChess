#include "headers/Interface.h"
#include "../configs.h"

Interface::Interface() {
  if (INTERFACE == INTERFACE_TYPE::CONSOLE) {
    game_window_ = std::make_shared<GameWindowConsole>();
    menu_window_ = std::make_shared<MenuWindowConsole>();
  }
}

std::shared_ptr<GameWindow> Interface::GetGameInterface() {
  return game_window_;
}

std::shared_ptr<MenuWindow> Interface::GetMenuInterface() {
  return menu_window_;
}
