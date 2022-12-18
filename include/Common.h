
#ifndef SNAKE_GAME_COMMON_H
#define SNAKE_GAME_COMMON_H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

const int BOARD_LENGTH = 40;
const int BOARD_WIDTH = 60;

const int SQUARE_SIZE = 15;

const int FRAMES = 30;

enum Direction {
    UP, DOWN, LEFT, RIGHT, STATIONARY
};

struct Coordinate {
    int x, y;
};

struct Dimension {
    int width, length;
};

struct Colour {
    int r, g, b;
};



#endif
