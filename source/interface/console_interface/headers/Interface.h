//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INTERFACE_INTERFACE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INTERFACE_INTERFACE_H_

#include "../../headers/actions/actions.h"
#include "../../headers/wrappers/wrappers.h"
#include "windows/windows.h"

class Interface {
 public:
  Interface();
  void DrawWindow();
  Action* GetWindowAction();
  void Rehearse();
  void SetMenu();
  void SetGame();
  void UpdateBoard(std::shared_ptr<Position>);
  PositionWrapper* GetPositionWrapper();
  ~Interface();
 private:
  Window* window_;
  PositionWrapper* position_wrapper_;
};

#endif
