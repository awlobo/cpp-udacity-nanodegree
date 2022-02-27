#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include <SDL2/SDL.h>

#include "snake.h"
// #include "game.h" // Don't know why it's not working with the include
class Game;

class Renderer
{
public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render(Snake const snake, SDL_Point const &food, SDL_Point const &poison, Game const &game);
    void UpdateWindowTitle(int score, int fps);
    void RenderPauseScreen();

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif