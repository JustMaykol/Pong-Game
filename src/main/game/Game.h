#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "../main.h"

#include "../menu/Menu.h"

#include "solo/SoloGame.h"
#include "duo/DuoGame.h"

class Game {

public:

    Font font;

    GameMode mode = UNKNOWN;

    Game();

    void init();

};

#endif //PROJECT_GAME_H
