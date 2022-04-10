//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_WINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_WINDOW_H_

#include "../../../headers/actions/actions.h"
#include "../../../headers/wrappers/wrappers.h"

class Window {
 public:
  Window();
  virtual void Draw(PositionWrapper*) = 0;
  virtual Action* GetAction() = 0;
  ~Window();
};

#endif
