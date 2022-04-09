//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_

#include "../../include interface logic.h"
#include "../../logic/headers/ErrorType.h"

class GameWindow : public Window{
 private:
  std::shared_ptr<GameWindow> instance_;
  GameWindow();
 public:
  std::shared_ptr<GameWindow> GetInstance();
  void Draw(PositionWrapper*);
  void DrawError(ErrorTypes);
//  void Rehearse();
  std::shared_ptr<Action> GetAction();
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_GAMEWINDOW_H_
