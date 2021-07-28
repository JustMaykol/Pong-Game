#include "Menu.h"

void rawText(Text &text);

void chooseText(Text &text);

Menu::Menu(Font &_f) {
    pong = new Text();

    pong->setFont(_f);
    pong->setString("PONG!");

    pong->setStyle(Text::Bold);
    pong->setOutlineThickness(5);

    pong->setCharacterSize(150);

    pong->setPosition(500, HEIGHT / 2 - 200);
    pong->setOrigin(pong->getLocalBounds().width / 2, pong->getLocalBounds().height / 2);

    for (auto &item : vector) {
        item = new Text();

        item->setFont(_f);
        item->setOutlineColor(Color::Yellow);
    }

    //
    vector[0]->setString("SOLO");
    vector[0]->setPosition(250, HEIGHT / 2 + 100);

    rawText(*vector[0]);

    //
    vector[1]->setString("DUO");
    vector[1]->setPosition(500, HEIGHT / 2 + 100);

    chooseText(*vector[1]);

    //
    vector[2]->setString("EXIT");
    vector[2]->setPosition(750, HEIGHT / 2 + 100);

    rawText(*vector[2]);
}

void Menu::draw(RenderWindow &window, int &idx) {
    for (auto &i : vector) {
        window.draw(*i);
    }

    if (idx >= 4000) {
        idx = 0;
    }

    if (idx >= 3000) {
        if (pong->getFillColor() != Color::Transparent)
            pong->setFillColor(Color::Transparent);

        if (pong->getOutlineColor() != Color::Transparent)
            pong->setOutlineColor(Color::Transparent);
    } else if (idx >= 2000) {
        if (pong->getFillColor() != Color::Yellow)
            pong->setFillColor(Color::Yellow);

        if (pong->getOutlineColor() != Color::Cyan)
            pong->setOutlineColor(Color::Cyan);
    } else if (idx >= 1000) {
        if (pong->getFillColor() != Color::Transparent)
            pong->setFillColor(Color::Transparent);

        if (pong->getOutlineColor() != Color::Transparent)
            pong->setOutlineColor(Color::Transparent);
    } else {
        if (pong->getFillColor() != Color::Cyan)
            pong->setFillColor(Color::Cyan);

        if (pong->getOutlineColor() != Color::Yellow)
            pong->setOutlineColor(Color::Yellow);
    }

    idx++;

    window.draw(*pong);
}

void Menu::moveLeft() {
    if (itemIndex - 1 >= 0) {
        rawText(*vector[itemIndex]);
        itemIndex--;
        chooseText(*vector[itemIndex]);
    }
}

void Menu::moveRight() {
    if (itemIndex + 1 < AMOUNT) {
        rawText(*vector[itemIndex]);
        itemIndex++;
        chooseText(*vector[itemIndex]);
    }
}

void rawText(Text &text) {
    text.setStyle(Text::Regular);
    text.setFillColor(Color::White);

    text.setCharacterSize(55);
    text.setOutlineThickness(0);

    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void chooseText(Text &text) {
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Red);

    text.setCharacterSize(65);
    text.setOutlineThickness(2.5);

    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}
