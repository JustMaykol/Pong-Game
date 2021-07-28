#ifndef PROJECT_DUOGAME_H
#define PROJECT_DUOGAME_H

#include "../../main.h"

#include "../abstract/AbstractGame.h"

class DuoGame : public AbstractGame {

public:

    explicit DuoGame(Font &_f);

    void draw(RenderWindow &window) override;

    void reset() override;

    void remove() override;

    friend ostream &operator<<(ostream &output, const DuoGame &game);

};

#endif //PROJECT_DUOGAME_H
