#include<SDL.h>
#include "Game.h"

//game object
Game* lamy = 0;

int main(int argc, char* argv[]) {

	lamy = new Game();

	lamy->init("Lamy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 450, SDL_WINDOW_SHOWN);

	while (lamy->isRunning()) {

		lamy->handleEvents();
		lamy->update();
		lamy->render();

	}

	lamy->clean();

	return 0;

}