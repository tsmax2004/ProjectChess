//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "headers/Interface.h"

Interface::Interface() {
  window_ = new MenuWindow();
  position_wrapper_ = nullptr;
}

void Interface::DrawWindow() {
  window_ -> Draw(position_wrapper_);
}

PositionWrapper* Interface::GetPositionWrapper() {
  return  position_wrapper_;
}

Action* Interface::GetWindowAction() {
  return window_ -> GetAction();
}

/*void Interface::Rehearse() {
  window_ -> Rehearse();
}*/

void Interface::SetGame() {
  window_ -> ~Window();
  window_ = new GameWindow();
}

void Interface::SetMenu() {
  window_ -> ~Window();
  window_ = new MenuWindow();
}

void Interface::UpdateBoard(std::shared_ptr<Position> new_pos_) {
  position_wrapper_ -> UpdatePosition(new_pos_);
}

Interface::~Interface() {
  window_ -> ~Window();
  position_wrapper_ -> ~PositionWrapper();
}