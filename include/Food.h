#ifndef SNAKE_GAME_FOOD_H
#define SNAKE_GAME_FOOD_H

#include "Common.h"
#include "NumberGenerator.h"
#include "Snake.h"

class Food {
     Coordinate food_coordinates_{};
     NumberGenerator &rng_;

public:
    Food();

    void GenerateNewCoordinates(Snake &snake);
    Coordinate GetCoordinates();

    bool FoodInsideSnake(Snake &snake) const;
};


#endif
