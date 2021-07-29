#include "BallObject.h"

BallObject::BallObject(float _x, float _y) {
    location = new Location(_x, _y);
    object = new RectangleShape();

    object->setSize({10, 10});
    object->setPosition({location->x, location->y});
    object->setOrigin(object->getLocalBounds().width / 2, object->getLocalBounds().height / 2);
}

void BallObject::update() {
    *location += {speedX, speedY};

    object->setPosition({location->x, location->y});
    object->setOrigin(object->getLocalBounds().width / 2, object->getLocalBounds().height / 2);
}

void BallObject::remove() {
    delete location;
    delete object;
}

void BallObject::reboundSide() {
    speedX = -speedX;
}

void BallObject::reboundPaddle() {
    location->y -= (speedY * 30);
    speedY = -speedY;
}

ostream &operator<<(ostream &output, const BallObject &object) {
    output << "Ball - [x:" << object.location->x << ", y:" << object.location->y << "]";
    return output;
}
