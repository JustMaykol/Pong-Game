#include "Location.h"

Location::Location()
        : x(0), y(0) {
}

Location::Location(float _x, float _y)
        : x(_x), y(_y) {
}

Location &operator+=(Location &location, const Location &update) {
    location.x += update.x;
    location.y += update.y;

    return location;
}
