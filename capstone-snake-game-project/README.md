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
   1. Linux: `./SnakeGame` or simply run `make`
   2. macOS: `./SnakeGame`
   3. Windows: `./SnakeGame.exe`

## New Features

* Add support for Windows and macOS
  * Windows - Add SDL2 libraries to project folder `lib`
* Toggle Pause and Resume with `Esc` key
* Display score and snake length when game is over
* Press `Q` to quit the game
* The snake can no longer turn back on itself (Small bug fix)
  * When two arrow keys were pressed quickly it was possible for the snake to do a 180 degree turn and die. Fixed by ignoring inputs until the snake has moved at least one tile.
* Poison (red squares)
  * 15% chance of spawning
  * Reduces speed to 0.2
  * Reverses direction
  * Effect lasts until snake eats food

## Rubric Points

1. The project demonstrates an understanding of C++ functions and control structures:
   1. main.cpp: lines 11, 18
   2. game.cpp: lines 97, 78, 108
   3. renderer.cpp: lines 53, 85
2. The project reads data from a file and process the data, or the program writes data to a file:
   1. main.cpp: line 36
   2. game.cpp: lines 12, 56
3. The project accepts user input and processes the input:
   1. main.cpp: line 17
4. Classes use appropriate access specifiers for class members:
   1. snake.h: lines 28-29, 43-46
   2. game.h: lines 18, 19, 32
5. The project uses Object Oriented Programming techniques:
   1. game.cpp: line 108
   2. game.h: lines 18, 19, 32, 17

## Ideas for the future

* Multiplayer
  * Two players can play against each other
* Add Menu window with options to start a new game, quit, etc.
* Retry button
  * Pressing the retry button will reset the game after you die

## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
