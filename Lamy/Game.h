#pragma once
#ifndef _Game_
#define _Game_

class Game {

public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width,
		int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	//access the running variable
	bool isRunning() {

		return running;

	}

private:

	SDL_Window* window;//window
	SDL_Renderer* renderer;//renderer

	SDL_Texture* texture;//texture variable
	SDL_Rect* square;//SDL rectangle for the square

	bool running;//indicates whether the game is running

};

#endif /*defined (_Game_)*/