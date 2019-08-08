#include<iostream>
#include"PlayObjs.h"//include headerfile
#include<SDL2/SDL.h>

//constructor
PlayObjs::PlayObjs(const Window& window, int w, int h, int x, int y, bool moving, bool primary) :
	Window(window), mw(w), mh(h), mx(x), my(y), mmoving(moving), mprimary(primary)
{

}

void PlayObjs::draw() {

}

void PlayObjs::pollEvents(SDL_Event& event) {
	//right arrow, left arrow, up arrow, down arrow
	//x to grab objects
}