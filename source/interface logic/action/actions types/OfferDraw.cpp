//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "MakeDrow.h"
OfferDraw::OfferDraw() = default;

std::shared_ptr<OfferDraw> OfferDraw::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<OfferDraw>(new OfferDraw());
  }
  return instance_;
}

void OfferDraw::GetAction(std::shared_ptr<Game> logic_) {
  logic_ -> OfferDraw();
}