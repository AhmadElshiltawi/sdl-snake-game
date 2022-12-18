#include "../include/Screen.h"

Screen::Screen() {
    screen_size_.width = SQUARE_SIZE * BOARD_WIDTH;
    screen_size_.length = SQUARE_SIZE * BOARD_LENGTH;
}

bool Screen::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return false;
    }

    window_ = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               screen_size_.width, screen_size_.length, SDL_WINDOW_SHOWN);

    renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

void Screen::DrawBackground() {
    SDL_Rect background;

    background.x = 0;
    background.y = 0;

    background.w = screen_size_.width;
    background.h = screen_size_.length;

    SDL_SetRenderDrawColor( renderer_, background_colour_.r, background_colour_.g,
                            background_colour_.b, 255);

    SDL_RenderDrawRect(renderer_, &background);
    SDL_RenderFillRect( renderer_, &background);
}

void Screen::RenderImage() {
    SDL_RenderPresent(renderer_);
}

void Screen::DrawSquare(Colour fill_colour, Colour border_colour, Coordinate coordinate) {
    SDL_Rect square;

    square.x = coordinate.x * SQUARE_SIZE;
    square.y = coordinate.y * SQUARE_SIZE;

    square.w = SQUARE_SIZE;
    square.h = SQUARE_SIZE;

    SDL_SetRenderDrawColor( renderer_, fill_colour.r, fill_colour.g,fill_colour.b, 255);
    SDL_RenderFillRect(renderer_, &square);

    SDL_SetRenderDrawColor( renderer_, border_colour.r, border_colour.g, border_colour.b, 255);
    SDL_RenderDrawRect(renderer_, &square);
}

void Screen::DrawSquare(Colour fill_colour, Coordinate coordinate) {
    SDL_Rect square;

    square.x = coordinate.x * SQUARE_SIZE;
    square.y = coordinate.y * SQUARE_SIZE;

    square.w = SQUARE_SIZE;
    square.h = SQUARE_SIZE;

    SDL_SetRenderDrawColor( renderer_, fill_colour.r, fill_colour.g,fill_colour.b, 255);
    SDL_RenderFillRect(renderer_, &square);
}

