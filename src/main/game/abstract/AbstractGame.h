#ifndef PROJECT_ABSTRACTGAME_H
#define PROJECT_ABSTRACTGAME_H

#include "../../main.h"

#include "../../object/ball/BallObject.h"
#include "../../object/paddle/PaddleObject.h"

class AbstractGame {

public:

    BallObject *ball{};

    PaddleObject *one{};
    PaddleObject *two{};

    Text oneText;
    Text twoText;

    virtual void draw(RenderWindow &window) = 0;

    virtual void reset() = 0;

    virtual void remove() = 0;

};

#endif //PROJECT_ABSTRACTGAME_H
