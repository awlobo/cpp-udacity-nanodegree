#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include <SDL2/SDL.h>

class Snake
{
public:
    enum class Direction
    {
        kUp,
        kDown,
        kLeft,
        kRight
    };

    Snake(int grid_width, int grid_height)
        : _grid_width(grid_width),
          _grid_height(grid_height),
          head_x(grid_width / 2),
          head_y(grid_height / 2) {}

    void Update();

    bool Moved() const;
    void SetMoved(const bool &moved);
    void GrowBody();
    bool IsGrowing();
    bool SnakeCell(int x, int y);
    bool IsAlive() const;

    bool IsPoisoned() const;
    void SetPoisoned(const bool &poisoned);

    Direction direction = Direction::kUp;

    float speed{0.1f};
    float previousSpeed{0.1f};
    int size{1};
    float head_x;
    float head_y;
    std::vector<SDL_Point> body;

private:
    void UpdateHead();
    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

    bool _growing{false};
    bool _alive{true};
    bool _poisoned{false};

    int _grid_width;
    int _grid_height;
};

#endif