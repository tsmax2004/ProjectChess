#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_POSITIONWRAPPER_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_POSITIONWRAPPER_H_
#include "../include_interface_logic.h"
#include "Position.h"

class PositionWrapper {
  private:
    std::shared_ptr<Position> position_;
  public:
    PositionWrapper(std::shared_ptr<Position>);
    POSITION_TYPE GetPositionType();
    std::shared_ptr<PieceWrapper> at(int, int);
    std::pair<int, int> GetBoardSize();
    void UpdatePosition(std::shared_ptr<Position>);
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_POSITIONWRAPPER_H_
