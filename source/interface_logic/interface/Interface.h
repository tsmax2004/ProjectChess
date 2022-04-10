//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INTERFACE_INTERFACE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INTERFACE_INTERFACE_H_

#include "../include_interface_logic.h"

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

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INTERFACE_INTERFACE_H_
