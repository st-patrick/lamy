//practice environment
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

int main(int argc, char* argv[]) {

	bool quit = false;
	SDL_Event event;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow("Practice Images", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, SDL_WINDOW_SHOWN);

		if (window != 0) {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}
		else {
			std::cout << "Window and renderer were not created" << std::endl;
			return 1;
		}
	}
	else {
		std::cout << "SDL Failed to initialize" << std::endl;
		return 1;
	}

	IMG_Init(IMG_INIT_JPG);
	surface = IMG_Load("images/background.jpg");
	if (surface == nullptr) {
		std::cout << "Unable to load image" << std::endl;
		return 1;
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		if (texture == nullptr) {
			std::cout << "Unable to create texture" << std::endl;
			return 1;
		}
	}

	while (!quit) {
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}

		SDL_Rect destRect = { 0, 0, 800, 450 };
		SDL_RenderCopy(renderer, texture, NULL, &destRect);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	IMG_Quit();

	return 0;
}