#ifndef GAME_H
#define GAME_H

#include <memory>
#include <random>

#include <SDL2/SDL.h>

#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game
{
public:
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);

    int GetScore() const;
    std::shared_ptr<Snake> GetSnake() const;

    // Game states
    bool IsPaused() const;
    void Pause();
    void Resume();

    void SetSpawnPoison();
    bool GetSpawnPoison() const;

private:
    std::shared_ptr<Snake> snake;

    // Snake snake;
    SDL_Point food;
    SDL_Point poison;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int _score{0};
    bool _running{true};
    bool _paused{false}; // Not paused by default
    bool _spawnPoison{false};

    void PlaceFood();
    void CheckFood(const int &x, const int &y);
    void PlacePoison();
    void CheckPoison(const int &x, const int &y);

    void Update();
};

#endif