#pragma once
#include<SDL.h>
#include"Window.h"//include Window for inheritance

class PlayObjs : public Window {
public:
	//player dimensions
	static const int PLAYER_W = 20;
	static const int PLAYER_H = 20;

	//object dimensions
	static const int OBJ_H = 10;
	static const int OBJ_W = 10;

	//player speed
	static const int PLAYER_V = 32;

	//constructor for use with a color
	PlayObjs(const Window& window, int w, int h, int x, int y, bool primary, int r, int g, int b, int a);

	//constructor for use with an image
	PlayObjs(const Window& window, int w, int h, int x, int y, bool primary, std::string& path);

	void drawColor();

	void drawImg();

	//poll events
	void pollEvents(SDL_Event& event);

protected:
	int mw, mh, mx, my, mr, mg, mb, ma;
	bool mprimary;
	std::string mpath;

};