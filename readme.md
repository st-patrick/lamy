to fix the include for SDL: https://stackoverflow.com/questions/10488775/sdl-h-no-such-file-or-directory-found-when-compiling


running on ubuntu:
https://stackoverflow.com/questions/10488775/sdl-h-no-such-file-or-directory-found-when-compiling

install SDL:
$ sudo apt-get install libsdl2-dev

and SDL_image
$ sudo apt-get install libsdl2-image-dev

include all SDL dependencies like so (with "SDL2/" leading):
#include <SDL2/SDL.h> 

# then compile using g++, the SDL libraries and all necessary file. Output executable "main"
$ g++ game.cpp main.cpp [...more files...] -o main -lSDL2main -lSDL2 -lSDL2_image
