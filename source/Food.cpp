#include "../include/Food.h"

Food::Food() : rng_(NumberGenerator::GetInstance()) {
    food_coordinates_.x = rng_.GenerateRandomWidth();
    food_coordinates_.y = rng_.GenerateRandomLength();
}

void Food::GenerateNewCoordinates(Snake &snake) {
    food_coordinates_.x = rng_.GenerateRandomWidth();
    food_coordinates_.y = rng_.GenerateRandomLength();

    while (FoodInsideSnake(snake)) {
        food_coordinates_.x = rng_.GenerateRandomWidth();
        food_coordinates_.y = rng_.GenerateRandomLength();
    }
}

Coordinate Food::GetCoordinates() {
    return food_coordinates_;
}

bool Food::FoodInsideSnake(Snake &snake) const {
    for (int i = 0; i < snake.GetLength(); i++) {
        Coordinate current_snake_node = snake.GetNode(i);

        if (current_snake_node.x == food_coordinates_.x || current_snake_node.y == food_coordinates_.y) {
            return true;
        }
    }
    return false;
}