#include "PaddleObject.h"

PaddleObject::PaddleObject(float _x, float _y) {
    location = new Location(_x, _y);
    object = new RectangleShape();

    object->setSize({200, 5});
    object->setPosition({location->x, location->y});
    object->setOrigin(object->getLocalBounds().width / 2, object->getLocalBounds().height / 2);
}

void PaddleObject::update() {
    object->setPosition({location->x, location->y});
    object->setOrigin(object->getLocalBounds().width / 2, object->getLocalBounds().height / 2);
}

void PaddleObject::remove() {
    delete location;
    delete object;
}

void PaddleObject::moveLeft() {
    if ((location->x - 100) - speed > 0)
        location->x -= speed;
}

void PaddleObject::moveRight() {
    if ((location->x + 100) + speed < WIDTH)
        location->x += speed;
}

ostream &operator<<(ostream &output, const PaddleObject &object) {
    output << "Paddle - [x:" << object.location->x << ", y:" << object.location->y << "]";
    return output;
}
