# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Project Structure

<img src="docs/structure.png"/>

```bash
ROOT
├── src  # Contain the main source files of the project
│   ├── main.cpp # The main file used to compile the project
│   ├── snake.h # Header for snake class
│   ├── snake.cpp # Functions for class that create snake's behaviour
│   ├── controller.h # Class that helps to capture user input
│   ├── controller.cpp # Contains functions for controller class
│   ├── game.h # Game class that helps to run the main game loop
│   ├── game.cpp # Functions for game class
│   ├── renderer.h # Contains defines class for SDL2 renderer
│   └── renderer.cpp # Function definitions for renderer class
├── docs  # Contain project related documentation
│   └── structure.png # Image with the basic structire of the project
├── lib  # Contain SDL2 libraries fow Windows
│   ├── SDL2 # Libraries for SDL2 (Windows)
│   └── SDL2TTf # Libraries for SDL2TTF (Windows)
├── res  # Contain resources for the game
│   └── roboto.ttf # Font used for the game
├── CMakeLists.txt # CMakeList for compiling the project
├── cmake # Folder that contains cmake files
│   └── FindSDL2.cmake # cmake file for proper linking of SDL2 library to the project
│   └── FindSDL2TTF.cmake # cmake file for proper linking of SDL2TTF library to the project
├── Makefile # (Only tested in Linux) Cmake wrapper for compiling/running/cleaning/debugging the project
└── README.md # The markdown file for explanation of the project
```

## Dependencies for Running Locally

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
    >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
  * Linux: `sudo apt install -y libsdl2-dev`
  * MacOS: `brew install sdl2`
  * Windows: libraries for MinGW included in the `lib` folder
* SDL2-TTF >= 2.0
  * Linux: `sudo apt install libsdl2-ttf-dev`
  * MacOS: `brew install sdl2_ttf`
  * Windows: libraries for MinGW included in the `lib` folder
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile:
   1. Linux and macOS:
      * `cmake .. && make` or
      * `cmake .. && cmake --build .` or
      * `cmake -B build && cmake --build build/`
   2. Windows: **With MingGW**
      * `cmake .. -G "MinGW Makefiles" && mingw32-make`
4. Run it:
   1. Linux: `./SnakeGame` or simply run `make` in the root folder
   2. macOS: `./SnakeGame`
   3. Windows: `./SnakeGame.exe`

## New Features

* Add Makefile wrapper for Cmake (only tested in Linux)
* Add support for Windows and macOS
  * Windows - Add SDL2 libraries to project folder `lib`
* Toggle Pause and Resume with `Esc` key
* Display score and snake length when game is over
* Press `Q` to quit the game
* The snake can no longer turn back on itself (Small bug fix)
  * When two arrow keys were pressed quickly it was possible for the snake to do a 180 degree turn and die. Fixed by ignoring inputs until the snake has moved at least one tile.
* Poison (red squares)
  * 20% chance of spawning
  * Reduces speed to 0.2
  * Reverses direction
  * Effect lasts until snake eats food

## Rubric Points

### Loops, Functions, I/O

| Criteria                                                                                       | Explanation and link(s)                                                       |
|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| The project demonstrates an understanding of C++ functions and control structures.             | The whole project is organized with proper use of functions and flow of data. |
| The project reads data from a file and process the data, or the program writes data to a file. | X                                                                             |
| The project accepts user input and processes the input.                                        | X                                                                             |

### Object Oriented Programming

| Criteria                                                                         | Explanation and link(s)                                                                                                                                                                                                                           |
|----------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| The project uses Object Oriented Programming techniques.                         | Per the project structure the code uses 4 classes : `Snake`, `Game`, `Controller` and `Renderer`. All the data and the control logic is encapsulated in them.                                                                                     |
| Classes use appropriate access specifiers for class members.                     | In the classes mentioned above, the data and member functions under private or public access specifiers based on the usability outside the class. Example:  Public - > `snake.h:41 - Snake::GetSize()` Private -> `game.h:47 Game::PlacePoison()` |
| Class constructors utilize member initialization lists.                          | Several functions ex: Snake constructor -> `snake.h:19`                                                                                                                                                                                           |
| Classes abstract implementation details from their interfaces.                   | All the header files contains proper documentation of the member functions ex: `snake.h` or `snake.cpp`                                                                                                                                           |
| Classes encapsulate behavior.                                                    | Contains private accesed by public getters and setters -> `GetSpeed() and SetSpeed snake.h:43-44 and 64`, or  `IsPoisoned() SetPoisoned -> snake.h:37-38`                                                                                         |
| Classes follow an appropriate inheritance hierarchy.                             | X                                                                                                                                                                                                                                                 |
| Overloaded functions allow the same function to operate on different parameters. | `UpdateHead() -> snake.h:68-69`                                                                                                                                                                                                                   |
| Derived class functions override virtual base class functions.                   | X                                                                                                                                                                                                                                                 |
| Templates generalize functions in the project.                                   | X                                                                                                                                                                                                                                                 |

### Memory Management

| Criteria                                                                                  | Explanation and link(s)                                                                                        |
|-------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| The project makes use of references in function declarations.                             | CheckFood `game.h:46` and CheckPoison `game.h:48` use pass by reference                                        |
| The project uses destructor(s) appropriately.                                             | Destructor for `Renderer -Z renderer.h:17` is used to close the window and perform cleanup after the game ends |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | X                                                                                                              |
| The project follows the Rule of 5.                                                        | X                                                                                                              |
| The project uses move semantics to move data, instead of copying it, where possible.      | X                                                                                                              |
| The project uses smart pointers instead of raw pointers.                                  | `snake` is a `shared_ptr` in `game.h:32`                                                                       |

### Concurrency

| Criteria                                     | Explanation and link(s) |
|----------------------------------------------|-------------------------|
| The project uses multithreading.             | X                       |
| A promise and future is used in the project. | X                       |
| A mutex or lock is used in the project.      | X                       |
| A condition variable is used in the project. | X                       |

## Ideas for the future

* Multiplayer
  * Two players can play against each other
* Menu window
  * Options to start a new game, quit, change grid size etc.
* Food
  * Different types of food (poisom food, potions, etc)
* Retry button
  * Pressing the retry button will reset the game after you die
* High Scores
  * The game will save the high scores to a file

## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
