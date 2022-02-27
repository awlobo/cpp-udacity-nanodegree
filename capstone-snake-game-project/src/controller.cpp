#include "controller.h"

#include <iostream>

#include "game.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const
{
    if (snake.IsPoisoned())
    {
        // Go to the opposite direction if snake is poisoned
        if (snake.direction != input || snake.GetSize() == 1)
            snake.direction = opposite;
    }
    else
    {
        if (snake.direction != opposite || snake.GetSize() == 1)
            snake.direction = input;
    }
    return;
}

bool Controller::IsDirectionKeyPressed(SDL_Keycode key) const
{
    return key == SDLK_UP || key == SDLK_DOWN || key == SDLK_LEFT || key == SDLK_RIGHT;
}

void Controller::HandleInput(bool &running, Snake &snake, Game &game) const
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            auto keyPressed = e.key.keysym.sym;
            if (snake.Moved() || !IsDirectionKeyPressed(keyPressed)) // Prevents snake from moving too fast
            {
                snake.SetMoved(false);
                switch (keyPressed)
                {
                case SDLK_UP:
                    ChangeDirection(snake, Snake::Direction::kUp,
                                    Snake::Direction::kDown);
                    break;

                case SDLK_DOWN:
                    ChangeDirection(snake, Snake::Direction::kDown,
                                    Snake::Direction::kUp);
                    break;

                case SDLK_LEFT:
                    ChangeDirection(snake, Snake::Direction::kLeft,
                                    Snake::Direction::kRight);
                    break;

                case SDLK_RIGHT:
                    ChangeDirection(snake, Snake::Direction::kRight,
                                    Snake::Direction::kLeft);
                    break;

                case SDLK_ESCAPE: // ESC key pauses the game
                    game.IsPaused() ? game.Resume() : game.Pause();
                    break;

                case SDLK_q: // Q key quits the game
                    running = false;
                    break;
                }
            }
        }
    }
}
