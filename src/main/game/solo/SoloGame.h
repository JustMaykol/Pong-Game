#ifndef PROJECT_SOLOGAME_H
#define PROJECT_SOLOGAME_H

#include "../../main.h"

#include "../abstract/AbstractGame.h"

class SoloGame : public AbstractGame {

public:

    long counter = 0;

    explicit SoloGame(Font &_f);

    void draw(RenderWindow &window) override;

    void reset() override;

    void remove() override;

    friend ostream &operator<<(ostream &output, const SoloGame &game);

};

#endif //PROJECT_SOLOGAME_H
