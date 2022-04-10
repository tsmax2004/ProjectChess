//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INCLUDE_LOGIC_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INCLUDE_LOGIC_H_

#include <iostream>
#include "../logic/headers/Position.h"

//wrappers' includes
#include "Head.h"
#include "wrappers/PieceWrapper.h"
#include "wrappers/PositionWrapper.h"
//interface's includes
#include "interface/Interface.h"
#include "interface/Window.h"
#include "interface/windows_types/GameWindow.h"
#include "interface/windows_types/MenuWindow.h"
//actions' includes
#include "action/Action.h"
#include "action/actions_types/CancelMove.h"
#include "action/actions_types/MakeMove.h"
#include "action/actions_types/OfferDraw.h"
#include "action/actions_types/Surrender.h"

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_INCLUDE_LOGIC_H_
