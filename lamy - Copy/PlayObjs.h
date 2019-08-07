#pragma once
#include"Window.h"//include Window for inheritance

class PlayObjs : public Window {
public:
	//object dimensions
	static const int PLAYER_W = 20;
	static const int PLAYER_H = 20;

	//player speed
	static const int PLAYER_V = 32;

	//constructor
	PlayObjs(const Window& window, int w, int h, int x, int y, bool moving, bool primary);

	void draw();

	//poll events
	void pollEvents(SDL_Event& event);

protected:
	int mw, mh, mx, my;
	bool mmoving, mprimary;

};