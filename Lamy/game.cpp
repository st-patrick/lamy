#include<SDL.h>
#include "Game.h"
#include<iostream>

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);

		if (window != 0) {
			std::cout << "renderer creation success\n";
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			//create surface
			SDL_Surface* surface;
			surface = SDL_CreateRGBSurface(0, 5, 5, 32, 255, 0, 0, 255);
			SDL_FillRect(surface, square, SDL_MapRGB(surface->format, 255, 0, 0));

		}
		else {
			std::cout << "renderer init fail\n";
			return false;//renderer init fail
		}

	}
	else {

		std::cout << "SDL init fail\n";
		return false; //SDL init fail

	}

	std::cout << "init success\n";
	running = true; //success: start main loop

}

void Game::render() {

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, 800, 450);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	std::cout << "cleaning window\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			//quit running if the user closes the program
			running = false;
			break;
		default:
			break;
		}
	}
}