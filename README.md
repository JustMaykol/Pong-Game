# Pong Game

El clásico **Pong** escrito en C++14 con [SFML](https://www.sfml-dev.org/), con modo contra la computadora y modo de dos jugadores en el mismo teclado.

## Modos de juego

| Modo | Descripción |
|---|---|
| **SOLO** | Juegas contra la computadora, que sigue la pelota |
| **DUO** | Dos jugadores en el mismo teclado |

## Controles

| Acción | Teclas |
|---|---|
| Moverse por el menú | `←` `→` o `A` `D` |
| Elegir opción | `Enter` |
| Mover la paleta (SOLO) | `←` `→` o `A` `D` |
| Jugador 1 (DUO) | `←` `→` |
| Jugador 2 (DUO) | `A` `D` |
| Volver al menú | `Esc` (el marcador se imprime en consola) |

## Compilar

Requiere un compilador con C++14, CMake 3.17+ y **SFML 2.5** (la API que usa no es compatible con SFML 3).

```bash
mkdir build && cd build
cmake ..
cmake --build .
./Project
```

El juego carga la fuente y el ícono desde `../src/resources/`, así que debe ejecutarse desde una carpeta dentro del repo (por ejemplo `build/`).

> El `CMakeLists.txt` se configuró originalmente para Windows (SFML en `C:/SFML` y DLLs de MinGW). En otros sistemas puede requerir ajustar las rutas de SFML.

## Estructura

```
src/
├── main/
│   ├── main.cpp            # punto de entrada
│   ├── game/               # bucle principal, modos SOLO y DUO
│   ├── menu/               # menú principal
│   ├── object/             # pelota y paletas
│   └── util/               # Location
└── resources/              # font.ttf, icon.png
```
