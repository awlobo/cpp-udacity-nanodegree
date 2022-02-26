#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>

#include "snake.h"
// #include "game.h" // Don't know why it's not working with the include

class Game;

class Controller
{
public:
    void HandleInput(bool &running, Snake &snake, Game &game) const;

private:
    void ChangeDirection(Snake &snake, Snake::Direction input,
                         Snake::Direction opposite) const;
};

#endif