# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Project Structure

<img src="docs/structure.png"/>

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
  * Windows: libraries for MinGW included in the `lib` folder
* SDL2-TTF >= 2.0
  * Linux: `sudo apt install libsdl2-ttf-dev`
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile:
   1. Linux: `cmake .. && make`
   2. Windows: **With MingGW** -> `cmake .. -G "MinGW Makefiles" && mingw32-make`
4. Run it:
   1. Linux: `./SnakeGame`
   2. Windows: `./SnakeGame.exe`

## New Features

* Add support for Windows
  * Add SDL2 libraries to project folder `lib`
* Toggle Pause and Resume with Esc key

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

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
