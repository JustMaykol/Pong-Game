# Pong Game

The classic **Pong**, written in C++14 with [SFML](https://www.sfml-dev.org/), with a single-player mode against the computer and a two-player mode on the same keyboard.

## Game modes

| Mode | Description |
|---|---|
| **SOLO** | Play against the computer, which follows the ball |
| **DUO** | Two players on the same keyboard |

## Controls

| Action | Keys |
|---|---|
| Navigate the menu | `←` `→` or `A` `D` |
| Select option | `Enter` |
| Move the paddle (SOLO) | `←` `→` or `A` `D` |
| Player 1 (DUO) | `←` `→` |
| Player 2 (DUO) | `A` `D` |
| Back to menu | `Esc` (the score is printed to the console) |

## Building

Requires a C++14 compiler, CMake 3.17+ and **SFML 2.5 or 2.6** (the API it uses is not compatible with SFML 3).

```bash
cmake -S . -B build
cmake --build build
cd build && ./pong
```

If SFML is installed in a non-standard location, point to it with `-DCMAKE_PREFIX_PATH=/path/to/sfml` (or `-DSFML_DIR=.../lib/cmake/SFML`). On Windows, `C:/SFML` is assumed and the DLLs are copied next to the executable.

The game loads its font and icon from `../src/resources/`, so it must be run from a folder inside the repo (for example `build/`).

## Structure

```
src/
├── main/
│   ├── main.cpp            # entry point
│   ├── game/               # main loop, SOLO and DUO modes
│   ├── menu/               # main menu
│   ├── object/             # ball and paddles
│   └── util/               # Location
└── resources/              # font.ttf, icon.png
```
