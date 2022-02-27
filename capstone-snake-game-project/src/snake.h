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
    bool CheckSnakeCell(int x, int y);

    // Snake movement
    Direction direction = Direction::kUp;
    bool Moved() const;
    void SetMoved(const bool &moved);

    // Snake status
    void GrowBody();
    bool IsGrowing();
    bool IsAlive() const;
    bool IsPoisoned() const;
    void SetPoisoned(const bool &poisoned);

    // Snake features
    int GetSize() const;
    void SetSize(const int &size);
    float GetSpeed() const;
    void SetSpeed(const float &speed);
    float GetPreviousSpeed() const;
    void SetPreviousSpeed(const float &speed);

    // Snake body
    float head_x;
    float head_y;
    std::vector<SDL_Point> body;

private:
    // Snake movement
    bool _moved{true};

    // Snake status
    bool _growing{false};
    bool _alive{true};
    bool _poisoned{false};

    // Snake features
    int _size{1};
    float _speed{0.1f};
    float _previousSpeed{0.1f};

    // Snake body
    void UpdateHead();
    void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
    int _grid_width;
    int _grid_height;
};

#endif
