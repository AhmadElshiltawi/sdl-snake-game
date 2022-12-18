#include "../include/Snake.h"

Snake::Snake() {
    snake_.push_back(Coordinate{BOARD_WIDTH/2, BOARD_LENGTH/2});
}

void Snake::Move() {
    switch (current_direction_) {
        case UP:
            snake_.push_front(Coordinate{snake_[0].x , snake_[0].y - 1});
            break;
        case DOWN:
            snake_.push_front(Coordinate{snake_[0].x , snake_[0].y + 1});
            break;
        case LEFT:
            snake_.push_front(Coordinate{snake_[0].x - 1 , snake_[0].y});
            break;
        case RIGHT:
            snake_.push_front(Coordinate{snake_[0].x + 1 , snake_[0].y});
            break;
        case STATIONARY:
            return;
    }
    snake_.pop_back();
}

void Snake::Lengthen() {
    switch (current_direction_) {
        case STATIONARY:
            break;
        case UP:
            snake_.push_back(Coordinate{snake_[0].x , snake_[0].y - 1});
            break;
        case DOWN:
            snake_.push_back(Coordinate{snake_[0].x , snake_[0].y + 1});
            break;
        case LEFT:
            snake_.push_back(Coordinate{snake_[0].x - 1 , snake_[0].y});
            break;
        case RIGHT:
            snake_.push_back(Coordinate{snake_[0].x + 1 , snake_[0].y});
            break;
    }
}

void Snake::SetDirection(Direction direction) {
    if (CheckDirectionValidity(direction) && !move_chosen) {
        this->previous_direction_ = this->current_direction_;
        this->current_direction_ = direction;
        move_chosen = true;
    }
}

Direction Snake::GetDirection() {
    return current_direction_;
}

void Snake::Print() {
    for (auto node : snake_) {
        std::cout << "[" << node.x << " " << node.y << "] ";
    }
    std::cout << std::endl;
}

Coordinate Snake::GetNode(int i) {
    return snake_[i];
}

int Snake::GetLength() {
    return (int) snake_.size();
}

bool Snake::CheckDirectionValidity(Direction direction) {
    if ((direction == UP && current_direction_ == DOWN) || (direction == DOWN && current_direction_ == UP)) {
        return false;
    }

    if ((direction == LEFT && current_direction_ == RIGHT) || (direction == RIGHT && current_direction_ == LEFT)) {
        return false;
    }
    return true;
}

void Snake::ResetMoveChosen() {
    move_chosen = false;
}

void Snake::SetPreviousDirection() {
    current_direction_ = previous_direction_;
}

bool Snake::CheckCollisionWithWall() {
    switch(current_direction_) {
        case UP:
            if (snake_[0].y - 1 < 0) {
                return true;
            }
            break;
        case DOWN:
            if (snake_[0].y + 1 >= BOARD_LENGTH) {
                return true;
            }
            break;
        case LEFT:
            if (snake_[0].x - 1 < 0) {
                return true;
            }
            break;
        case RIGHT:
            if (snake_[0].x + 1 >= BOARD_WIDTH) {
                return true;
            }
            break;
        case STATIONARY:
            return false;
    }
    return false;
}

void Snake::RemoveFrontNode() {
    snake_.pop_front();
}

void Snake::Clear() {
    snake_.clear();
}

void Snake::InsertFirstNode() {
    if (snake_.empty()) {
        snake_.push_back(Coordinate{BOARD_WIDTH/2, BOARD_LENGTH/2});
    }
}

bool Snake::CheckCollisionWithSelf() {
    int snake_length = (int) snake_.size();

    for (int i = 0; i < snake_length; i++) {
        for (int j = 0; j < snake_length; j++) {
            if (i != j) {
                if (snake_[i].x == snake_[j].x && snake_[i].y == snake_[j].y) {
                    return true;
                }
            }
        }
    }
    return false;
}
