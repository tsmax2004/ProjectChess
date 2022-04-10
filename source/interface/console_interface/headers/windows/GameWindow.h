//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_

#include "Window.h"
#include "GameWindow.h"

class GameWindow : public Window{
 private:
  std::shared_ptr<GameWindow> instance_;
  GameWindow();
 public:
  std::shared_ptr<GameWindow> GetInstance();
  void Draw(PositionWrapper*);
  std::shared_ptr<Action> GetAction();
};

#endif
