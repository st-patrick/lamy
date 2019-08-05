# running on ubuntu

to fix the include for SDL: https://stackoverflow.com/questions/10488775/sdl-h-no-such-file-or-directory-found-when-compiling

running on ubuntu:
https://stackoverflow.com/questions/10488775/sdl-h-no-such-file-or-directory-found-when-compiling

install SDL:
$ sudo apt-get install libsdl2-dev

and SDL_image
$ sudo apt-get install libsdl2-image-dev

include all SDL dependencies like so (with "SDL2/" leading):
#include <SDL2/SDL.h> 

then compile using g++, the SDL libraries and all necessary file. Output executable "main"
$ g++ game.cpp main.cpp [...more files...] -o main -lSDL2main -lSDL2 -lSDL2_image



# running on macOS

more or less following this guide: https://medium.com/@edkins.sarah/set-up-sdl2-on-your-mac-without-xcode-6b0c33b723f7

first, install SDL dependencies:
$ brew install SDL2
$ brew install SDL2_image

then, change all the SDL2 includes to SDL2/file.h, just like in Ubuntu, e.g. #include<SDL.h> becomes #include<SDL2/SDL.h>