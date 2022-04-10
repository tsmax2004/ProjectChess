#include "headers/Interface.h"

Interface::Interface(): game_window_(), menu_window_() {}

GameWindow Interface::GetGameInterface() {
  return game_window_;
}

MenuWindow Interface::GetMenuInterface() {
  return menu_window_;
}
