#include "SoloGame.h"

SoloGame::SoloGame(Font &_f) {
    ball = new BallObject(BALL_START_X, BALL_START_Y);

    one = new PaddleObject(ONE_START_X, ONE_START_Y);
    two = new PaddleObject(TWO_START_X, TWO_START_Y);

    oneText.setFont(_f);

    oneText.setString(to_string(oneScore));
    oneText.setCharacterSize(60);

    oneText.setPosition(400, HEIGHT / 2);
    oneText.setOrigin(oneText.getLocalBounds().width / 2, oneText.getLocalBounds().height / 2);

    //

    twoText.setFont(_f);

    twoText.setString(to_string(twoScore));
    twoText.setCharacterSize(60);

    twoText.setPosition(600, HEIGHT / 2);
    twoText.setOrigin(oneText.getLocalBounds().width / 2, oneText.getLocalBounds().height / 2);
}

void SoloGame::draw(RenderWindow &window) {
    if (counter == 10000) {
        counter = 0;
    }

    counter++;

    if (ball->object->getGlobalBounds().left > (two->object->getGlobalBounds().left) + 50) {
        if (counter % 99 == 0) {
            two->moveRight();
        }
    }

    if (ball->object->getGlobalBounds().left < (two->object->getGlobalBounds().left) + 50) {
        if (counter % 99 == 0) {
            two->moveLeft();
        }
    }

    if (ball->object->getGlobalBounds().top < 0) {
        ball->location->x = BALL_START_X;
        ball->location->y = BALL_START_Y;

        oneScore++;

        oneText.setString(to_string(oneScore));
    }

    if (ball->object->getGlobalBounds().top > HEIGHT) {
        ball->location->x = BALL_START_X;
        ball->location->y = BALL_START_Y;

        twoScore++;

        twoText.setString(to_string(twoScore));
    }

    if (ball->object->getGlobalBounds().left < 0 || ball->object->getGlobalBounds().left + 10 > WIDTH) {
        ball->reboundSide();
    }

    if (ball->object->getGlobalBounds().intersects(one->object->getGlobalBounds())) {
        ball->reboundPaddle();
    }

    if (ball->object->getGlobalBounds().intersects(two->object->getGlobalBounds())) {
        ball->reboundPaddle();
    }

    ball->update();

    one->update();
    two->update();

    window.draw(oneText);
    window.draw(twoText);

    window.draw(*ball->object);

    window.draw(*one->object);
    window.draw(*two->object);
}

void SoloGame::reset() {
    oneScore = 0;
    twoScore = 0;

    oneText.setString(to_string(oneScore));
    twoText.setString(to_string(twoScore));

    ball->speedX = .1F;
    ball->speedY = .1F;

    ball->location->x = BALL_START_X;
    ball->location->y = BALL_START_Y;

    one->location->x = ONE_START_X;
    one->location->y = ONE_START_Y;

    two->location->x = TWO_START_X;
    two->location->y = TWO_START_Y;
}

void SoloGame::remove() {
    ball->remove();

    one->remove();
    two->remove();

    delete ball;

    delete one;
    delete two;
}

ostream &operator<<(ostream &output, const SoloGame &game) {
    auto t = time(nullptr);
    auto lt = *localtime(&t);

    output << "SoloGame [" << put_time(&lt, "%m:%d:%Y %H:%M:%S") << "]" << endl << endl;
    output << *game.ball << endl << endl;
    output << "First " << *game.one << " : " << oneScore << endl;
    output << "Second " << *game.two << " : " << twoScore << endl;

    return output;
}
