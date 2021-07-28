#ifndef PROJECT_PADDLEOBJECT_H
#define PROJECT_PADDLEOBJECT_H

#include "../../main.h"
#include "../../util/Location.h"
#include "../abstract/AbstractObject.h"

class PaddleObject : public AbstractObject {

public:

    float speed = 7.5F;

    PaddleObject(float _x, float _y);

    void update() override;

    void remove() override;

    void moveLeft();

    void moveRight();

    friend ostream &operator<<(ostream &output, const PaddleObject &object);

};

#endif //PROJECT_PADDLEOBJECT_H
