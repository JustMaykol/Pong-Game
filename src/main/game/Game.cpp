#include "Game.h"

Game::Game() {
    if (!font.loadFromFile("../src/resources/font.ttf")) {
        throw runtime_error("font error");
    }
}

void Game::init() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "PONG!", Style::Titlebar | Style::Close);

    int idx;

    Image icon;

    if (icon.loadFromFile("../src/resources/icon.png"))
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    mode = UNKNOWN;

    Menu menu(font);

    SoloGame soloGame(font);
    DuoGame duoGame(font);

    while (window.isOpen()) {
        Event event{};

        window.clear(Color(22, 22, 22));

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                soloGame.remove();
                duoGame.remove();

                window.close();
                return;
            }

            switch (mode) {
                case SOLO:
                    if (event.type == Event::KeyReleased) {
                        if (event.key.code == Keyboard::Escape) {
                            cout << soloGame << endl;
                            soloGame.reset();
                            mode = UNKNOWN;
                        }
                    }

                    if (event.type == Event::KeyPressed) {
                        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                            soloGame.one->moveLeft();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                            soloGame.one->moveRight();
                        }
                    }

                    break;
                case DUO:
                    if (event.type == Event::KeyReleased) {
                        if (event.key.code == Keyboard::Escape) {
                            cout << duoGame << endl;
                            duoGame.reset();
                            mode = UNKNOWN;
                        }
                    }

                    if (event.type == Event::KeyPressed) {
                        if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::A)) {
                            duoGame.one->moveLeft();
                            duoGame.two->moveLeft();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::D)) {
                            duoGame.one->moveRight();
                            duoGame.two->moveRight();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::D)) {
                            duoGame.one->moveLeft();
                            duoGame.two->moveRight();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::A)) {
                            duoGame.one->moveRight();
                            duoGame.two->moveLeft();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Left)) {
                            duoGame.one->moveLeft();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Right)) {
                            duoGame.one->moveRight();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::A)) {
                            duoGame.two->moveLeft();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::D)) {
                            duoGame.two->moveRight();
                        }
                    }

                    break;
                case UNKNOWN:
                    switch (event.type) {
                        case Event::KeyReleased:
                            switch (event.key.code) {
                                case Keyboard::Left:
                                case Keyboard::A:
                                    menu.moveLeft();
                                    break;

                                case Keyboard::Right:
                                case Keyboard::D:
                                    menu.moveRight();
                                    break;

                                case Keyboard::Return:
                                    switch (menu.itemIndex) {
                                        case 0:
                                            mode = SOLO;
                                            break;
                                        case 1:
                                            mode = DUO;
                                            break;
                                        case 2:
                                            soloGame.remove();
                                            duoGame.remove();

                                            window.close();
                                            break;
                                    }
                                    break;

                                default:
                                    break;

                            }

                            break;

                        default:
                            break;
                    }

                    break;
            }
        }

        switch (mode) {
            case SOLO:
                soloGame.draw(window);
                break;
            case DUO:
                duoGame.draw(window);
                break;
            case UNKNOWN:
                menu.draw(window, idx);
                break;
        }

        window.display();
    }
}
