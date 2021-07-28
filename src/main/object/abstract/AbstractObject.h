#ifndef PROJECT_ABSTRACTOBJECT_H
#define PROJECT_ABSTRACTOBJECT_H

#include "../../main.h"
#include "../../util/Location.h"

class AbstractObject {

public:

    Location *location{};

    RectangleShape *object{};

    virtual void update() = 0;

    virtual void remove() = 0;

};

#endif //PROJECT_ABSTRACTOBJECT_H
