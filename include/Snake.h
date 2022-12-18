#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H

#include <deque>
#include "Common.h"

class Snake {
    std::deque<Coordinate> snake_;
    Direction current_direction_ = STATIONARY;
    Direction previous_direction_ = STATIONARY;

    bool move_chosen = false;

    bool CheckDirectionValidity(Direction direction);

public:
    Snake();
    void Move();
    void Lengthen();

    void SetDirection(Direction direction);
    Direction GetDirection();

    void Print();

    Coordinate GetNode(int i);
    int GetLength();

    void ResetMoveChosen();
    void SetPreviousDirection();

    bool CheckCollisionWithWall();
    bool CheckCollisionWithSelf();

    void RemoveFrontNode();

    void Clear();

    void InsertFirstNode();
};


#endif
