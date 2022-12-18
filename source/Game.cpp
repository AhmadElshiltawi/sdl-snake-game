#include "../include/Game.h"

void Game::Run() {
    screen_.Initialize();

    while (!game_closed_){
        screen_.DrawBackground();

        HandleEvents();

        if (food_.GetCoordinates().x == snake_.GetNode(0).x && food_.GetCoordinates().y == snake_.GetNode(0).y) {
            food_.GenerateNewCoordinates(snake_);
            snake_.Lengthen();
        }

        if (game_paused_) {
            if (snake_.GetDirection() != STATIONARY) {
                snake_.SetDirection(STATIONARY);
            }
        }

        if (snake_.CheckCollisionWithWall() || snake_.CheckCollisionWithSelf()) {
            snake_dead_ = true;
            PerformDeathScene();
            continue;
        }

        snake_.Move();

        DrawFrame();

        screen_.RenderImage();

        SDL_Delay(1000 / FRAMES);
        snake_.ResetMoveChosen();
    }
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
            game_closed_ = true;
        }

        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_p) {
                game_paused_ = !game_paused_;
                if (!game_paused_) {
                    snake_.SetPreviousDirection();
                }
            }
            if (event.key.keysym.sym == SDLK_SPACE) {
                snake_.SetDirection(STATIONARY);
                snake_.Clear();
                snake_.InsertFirstNode();
                food_.GenerateNewCoordinates(snake_);
                snake_dead_ = false;
            }
        }

        if (event.type == SDL_KEYDOWN && !game_paused_) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    snake_.SetDirection(UP);
                    break;
                case SDLK_DOWN:
                    snake_.SetDirection(DOWN);
                    break;
                case SDLK_RIGHT:
                    snake_.SetDirection(RIGHT);
                    break;
                case SDLK_LEFT:
                    snake_.SetDirection(LEFT);
                    break;
            }
        }
    }
}

void Game::DrawFrame() {
    screen_.DrawSquare(food_colour_, food_.GetCoordinates());

    for (int i = 0; i < snake_.GetLength(); i++) {
        screen_.DrawSquare(snake_fill_colour_, snake_border_colour_, snake_.GetNode(i));
    }
}

void Game::PerformDeathScene() {
    int snake_length = snake_.GetLength();

    for (int i = 0; i < snake_length; i++) {
        screen_.DrawBackground();

        snake_.RemoveFrontNode();

        SDL_Delay(1000 / (FRAMES - (FRAMES / 2)));

        DrawFrame();

        screen_.RenderImage();
    }
    snake_.SetDirection(STATIONARY);
}
