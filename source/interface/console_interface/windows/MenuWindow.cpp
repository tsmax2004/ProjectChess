//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "../headers/windows/MenuWindow.h"
MenuWindow::MenuWindow() = default;

std::shared_ptr<MenuWindow> MenuWindow::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<MenuWindow>(new MenuWindow());
  }
  return instance_;
}

void MenuWindow::Draw(std::shared_ptr<PositionWrapper>) {}

std::shared_ptr<Action> MenuWindow::GetAction() {return nullptr;}