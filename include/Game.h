#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H

#include "Screen.h"
#include "Snake.h"
#include "Common.h"
#include "Food.h"

class Game {
private:
    bool game_closed_ = false;
    bool game_paused_ = false;
    bool snake_dead_ = false;

    Screen screen_;
    Snake snake_;
    Food food_;

    Colour background_colour_ = {49, 49, 49};

    Colour snake_fill_colour_ = {237, 237, 237};
    Colour snake_border_colour_ = {216, 217, 207};

    Colour food_colour_ = {255, 135, 135};

private:
    void PerformDeathScene();
public:
    void Run();
    void HandleEvents();
    void DrawFrame();
};


#endif
