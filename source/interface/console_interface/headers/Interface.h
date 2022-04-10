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
  std::shared_ptr<Action> GetWindowAction();
  void Rehearse();
  void SetMenu();
  void SetGame();
  void UpdateBoard(std::shared_ptr<Position>);
  std::shared_ptr<PositionWrapper> GetPositionWrapper();
  ~Interface();
 private:
  std::shared_ptr<Window> window_;
  std::shared_ptr<PositionWrapper> position_wrapper_;
};

#endif
