#include<iostream>
#include"Tiles.h"//tile header file
#include<SDL.h>

Tiles::Tiles(const Window& window, int x, int y, int type) :
	Window(window), mx(x), my(y), mtype(type)
{
	//set position
	mbox.x = x;
	mbox.y = y;

	//set dimensions
	mbox.w = TILE_WIDTH;
	mbox.h = TILE_HEIGHT;

	//set type and accessibility
	mtype = type;
	switch (type) {
	case 0:
		mlocked = false;
		break;
	case 1:
		mlocked = false;
		break;
	case 2:
		mlocked = true;
		break;
	case 3:
		mlocked = true;
		break;
	default:
		break;
	}
}

int Tiles::getType() {
	return mtype;
}

SDL_Rect Tiles::getBox() {
	return mbox;
}

bool Tiles::getStatus() {
	return mlocked;
}