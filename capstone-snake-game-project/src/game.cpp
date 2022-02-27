#include "game.h"

#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(new Snake(grid_width, grid_height)),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
    PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    while (_running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(_running, *snake.get(), *this);
        Update();
        renderer.Render(*snake.get(), food, poison, *this);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            renderer.UpdateWindowTitle(_score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::PlaceFood()
{
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake->CheckSnakeCell(x, y))
        {
            food.x = x;
            food.y = y;
            return;
        }
    }
}

void Game::PlacePoison()
{
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item
        // or food before placing poison
        if (!snake->CheckSnakeCell(x, y) && !(x == food.x && y == food.y))
        {
            poison.x = x;
            poison.y = y;
            return;
        }
    }
}

bool Game::GetSpawnPoison() const
{
    return _spawnPoison;
}

void Game::SetSpawnPoison()
{
    if (!_spawnPoison)
    {
        srand(time(NULL));

        // Generate secret number between 1 and 100
        int randomNumber = rand() % 100 + 1;

        // If number is below 20, there will be poison
        if (randomNumber <= 20)
        {
            _spawnPoison = true;
        }
        else
        {
            _spawnPoison = false;
        }
    }
}

void Game::Update()
{
    if (IsPaused())
    {
        return;
    }

    if (!snake->IsAlive())
    {
        std::string msgText{"Score: " + std::to_string(_score) + "\n Size: " + std::to_string(snake->GetSize())};
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GAME OVER!", msgText.c_str(), NULL);
        // Stops the game & prevents the MessageBox from appearing again
        _running = false;
        return;
    }

    snake->Update();

    int new_x = static_cast<int>(snake->head_x);
    int new_y = static_cast<int>(snake->head_y);

    CheckFood(new_x, new_y);
    CheckPoison(new_x, new_y);
}

void Game::CheckFood(const int &x, const int &y)
{
    // Check if there's food over here
    if (food.x == x && food.y == y)
    {
        _score++;
        PlaceFood();
        // Grow and cure snake and increase speed
        snake->GrowBody();
        snake->SetPoisoned(false);
        _spawnPoison = false;
        if (snake->GetPreviousSpeed() != snake->GetSpeed())
        {
            // Resets the speed after eating poison
            snake->SetSpeed(snake->GetPreviousSpeed());
        }
        else
        {
            auto newSpeed = snake->GetSpeed();
            snake->SetSpeed(newSpeed += 0.01);
            snake->SetPreviousSpeed(snake->GetSpeed());
        }

        SetSpawnPoison();
        if (GetSpawnPoison())
        {
            PlacePoison();
        }
    }
}

// Check if there's poison over here and only if there's poison in the board
void Game::CheckPoison(const int &x, const int &y)
{
    if (GetSpawnPoison())
    {
        if (poison.x == x && poison.y == y)
        {
            _spawnPoison = false;
            snake->SetPoisoned(true);
            snake->SetPreviousSpeed(snake->GetSpeed());
            snake->SetSpeed(0.1);
            _score--;
        }
    }
}

void Game::Pause() { _paused = true; }

void Game::Resume() { _paused = false; }

int Game::GetScore() const { return _score; }

bool Game::IsPaused() const { return _paused; }

std::shared_ptr<Snake> Game::GetSnake() const { return snake; }
