#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "../main.h"

#define AMOUNT 3

class Menu {

    Text *pong{};
    Text *vector[AMOUNT]{};

public:

    int itemIndex = 1;

    explicit Menu(Font &_f);

    void draw(RenderWindow &window, int &idx);

    void moveLeft();

    void moveRight();

};

#endif //PROJECT_MENU_H
