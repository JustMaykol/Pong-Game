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

Requiere un compilador con C++14, CMake 3.17+ y **SFML 2.5 o 2.6** (la API que usa no es compatible con SFML 3).

```bash
cmake -S . -B build
cmake --build build
cd build && ./pong
```

Si SFML está instalado en una ruta no estándar, indícala con `-DCMAKE_PREFIX_PATH=/ruta/a/sfml` (o `-DSFML_DIR=.../lib/cmake/SFML`). En Windows se asume `C:/SFML` y las DLL se copian junto al ejecutable.

El juego carga la fuente y el ícono desde `../src/resources/`, así que debe ejecutarse desde una carpeta dentro del repo (por ejemplo `build/`).

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
