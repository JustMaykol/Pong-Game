#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include <string>
#include <random>
#include <iomanip>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define WIDTH 1000.0F
#define HEIGHT 800.0F

#define BALL_START_X 500.0F
#define BALL_START_Y 400.0F

#define ONE_START_X 850
#define ONE_START_Y 750

#define TWO_START_X 150
#define TWO_START_Y 50

using namespace sf;
using namespace std;

static int oneScore = 0;
static int twoScore = 0;

enum GameMode {

    SOLO, DUO, UNKNOWN

};

#endif //PROJECT_MAIN_H
