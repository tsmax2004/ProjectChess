#include "headers/Head.h"

Head::Head() = default;

std::shared_ptr<Action> Head::GetInterFaceAction() {
    return interface_->GetWindowAction();
}

void Head::MenuCycle() {

}

void Head::GameCycle() {

}