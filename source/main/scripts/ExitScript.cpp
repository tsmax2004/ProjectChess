#include "../headers/scripts/scripts.h"

ExitScript::ExitScript() = default;

void ExitScript::Initialize() {
  instance_ = std::shared_ptr<ExitScript>(new ExitScript());
}

std::shared_ptr<ExitScript> ExitScript::Get() {
  return instance_;
}

std::shared_ptr<Script> ExitScript::Run() {
  return nullptr;
}
