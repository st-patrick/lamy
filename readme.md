# install dependencies on ubuntu

install SDL:
$ sudo apt-get install libsdl2-dev

and SDL_image
$ sudo apt-get install libsdl2-image-dev


# install dependencies on macOS

first, install SDL dependencies:
$ brew install SDL2

$ brew install SDL2_image


# next steps for macOS + Ubuntu

include all SDL dependencies like so (with "SDL2/" leading):
#include <SDL2/SDL.h>

then compile using g++, the SDL libraries and all necessary file. Output executable "main"
$ g++ game.cpp main.cpp [...more files...] -o main -lSDL2main -lSDL2 -lSDL2_image

or, more concise

$ g++ *.cpp -o main -lSDL2main -lSDL2 -lSDL2_image