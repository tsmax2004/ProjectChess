#include "../headers/scripts/MenuScript.h"

MenuScript::MenuScript(MenuWindow interface): interface_(interface) {}

void MenuScript::Initialize(MenuWindow interface) {
  instance_ = std::shared_ptr<MenuScript>(new MenuScript(interface));
}

std::shared_ptr<MenuScript> MenuScript::Get() {
  return instance_;
}

std::shared_ptr<Script> MenuScript::Run() {
  return GameScript::Get();
}
