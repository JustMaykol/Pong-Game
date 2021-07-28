#ifndef PROJECT_BALLOBJECT_H
#define PROJECT_BALLOBJECT_H

#include "../../main.h"
#include "../../util/Location.h"
#include "../abstract/AbstractObject.h"

class BallObject : public AbstractObject {

public:

    float speedX = .1F;
    float speedY = .1F;

    BallObject(float _x, float _y);

    void update() override;

    void remove() override;

    void reboundSide();

    void reboundPaddle();

    friend ostream &operator<<(ostream &output, const BallObject &game);

};

#endif //PROJECT_BALLOBJECT_H
