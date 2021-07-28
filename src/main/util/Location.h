#ifndef PROJECT_LOCATION_H
#define PROJECT_LOCATION_H

#include "../main.h"

class Location {

public:

    float x;
    float y;

    Location();

    Location(float _x, float _y);

    friend Location &operator+=(Location &location, const Location &Location);

};

#endif //PROJECT_LOCATION_H
