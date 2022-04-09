//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "CancelMove.h"

CancelMove::CancelMove() = default;

std::shared_ptr<CancelMove> CancelMove::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<CancelMove>(new CancelMove());
  }
  return instance_;
}

void CancelMove::GetAction(std::shared_ptr<Game> logic_) {
  logic_ -> CancelMove();
}