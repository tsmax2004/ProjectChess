//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_

#include "Window.h"

class GameWindow : public Window{
 private:
  static std::shared_ptr<GameWindow> instance_;
  GameWindow();
 public:
  static std::shared_ptr<GameWindow> GetInstance();
  void Draw(std::shared_ptr<PositionWrapper>) override;
  std::shared_ptr<Action> GetAction() override;
};

#endif
