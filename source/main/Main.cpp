#include "headers/Main.h"

Main::Main(): interface_() {
  InitializeScripts();
  Run();
}

void Main::Run() {
  std::shared_ptr<Script> current_script = MenuScript::Get();
  while (current_script) {
    current_script = current_script->Run();
  }
}

void Main::InitializeScripts() {
  GameScript::Initialize(interface_.GetGameInterface());
  MenuScript::Initialize(interface_.GetMenuInterface());
  ExitScript::Initialize();
}
