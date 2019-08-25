#pragma once
#include<SDL.h>//include SDL2
#include"Window.h"//include Window for inheritance

class Tiles : public Window {
public:

	//constructor
	Tiles(const Window& window, int x, int y, int type);

	//total number of tiles
	const int TOTAL_TILES = 576;

protected:
	//tile position variables
	int mx, my, mtype;

	//accessibility
	bool mlocked;//true for locked, false for accessible

	//collision box
	SDL_Rect mbox;

	//return tile information
	int getType();//tile type
	SDL_Rect getBox();//collision box
	bool getStatus();//accessible or not

	//dimensions of tiles
	const int TILE_WIDTH = 32;
	const int TILE_HEIGHT = 32;

	//dimensions of level
	const int LEVEL_WIDTH = 2 * m_width;
	const int LEVEL_HEIGHT = 2 * m_height;

	//dimensions of screen
	const int SCREEN_WIDTH = m_width;
	const int SCREEN_HEIGHT = m_height;

	//tile types
	const int OPEN = 0;
	const int OPEN_DOOR = 1;
	const int CLOSED_DOOR = 2;
	const int WALL = 3;

};