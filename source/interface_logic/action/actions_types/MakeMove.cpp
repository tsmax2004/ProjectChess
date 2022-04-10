//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "MakeMove.h"

MakeMove::MakeMove(int from_y_, int from_x_, int to_y_, int to_x_) {
  from_square_ = {from_y_, from_x_};
  to_square_ = {to_y_, to_x_};
}

std::shared_ptr<MakeMove> MakeMove::GetInstance(int from_y_, int from_x_, int to_y_, int to_x_) {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<MakeMove>(new MakeMove(from_y_, from_x_, to_y_, to_x_));
  }
  from_square_ = {from_y_, from_x_};
  to_square_ = {to_y_, to_x_};
  return instance_;
}

void MakeMove::GetAction(std::shared_ptr<Game> logic_) {
  logic_ -> MakeMove(from_square_.first, from_square_.second, to_square_.first, to_square_.second);
}