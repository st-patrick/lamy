//practice environment
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

int main(int argc, char* argv[]) {
	
	SDL_Event event;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	SDL_Window* window = NULL;

	SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(
		800, 450,
		0, &window, &renderer
	);
	IMG_Init(IMG_INIT_PNG);
	texture = IMG_LoadTexture(renderer, "images\background.png");
	if (texture == NULL) {
		std::cout << "Unsuccessful" << std::endl;
	}
	while (1) {
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
	SDL_DestroyTexture(texture);
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}