//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "headers/Interface.h"

Interface::Interface() {
  window_ = MenuWindow::GetInstance();
  position_wrapper_ = nullptr;
}

void Interface::DrawWindow() {
  window_ -> Draw(position_wrapper_);
}

std::shared_ptr<PositionWrapper> Interface::GetPositionWrapper() {
  return  position_wrapper_;
}

std::shared_ptr<Action> Interface::GetWindowAction() {
  return window_ -> GetAction();
}

/*void Interface::Rehearse() {
  window_ -> Rehearse();
}*/

void Interface::SetGame() {
  window_ = GameWindow::GetInstance();
}

void Interface::SetMenu() {
  window_ = MenuWindow::GetInstance();
}

void Interface::UpdateBoard(std::shared_ptr<Position> new_pos_) {
  position_wrapper_ -> UpdatePosition(new_pos_);
}