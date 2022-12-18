#ifndef SNAKE_GAME_SCREEN_H
#define SNAKE_GAME_SCREEN_H

#include "Common.h"

class Screen {

    Dimension screen_size_ {};
    Colour background_colour_ {49, 49, 49};

    SDL_Window *window_{};
    SDL_Renderer *renderer_{};

public:
    Screen();
    bool Initialize();
    void DrawBackground();
    void RenderImage();
    void DrawSquare(Colour fill_colour,  Colour border_colour, Coordinate coordinate);
    void DrawSquare(Colour fill_colour, Coordinate coordinate);
};


#endif
