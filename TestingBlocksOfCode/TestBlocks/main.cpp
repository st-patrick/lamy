#include<SDL.h>
#include<SDL_keycode.h>

/*
The close button only clicks at certain times, and the movement is off,
it needs to be fixed.
*/

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

bool running;
SDL_Event event;

int sqrx = 10;
int sqry = 10;
int sqrx_vel = 0;
int sqry_vel = 0;

void checkKeys() {

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			//key press events
		case SDL_KEYDOWN:
			//handle key presses
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				sqrx_vel = -1;
				break;
			case SDLK_RIGHT:
				sqrx_vel = 1;
				break;
			case SDLK_UP:
				sqry_vel = -1;
				break;
			case SDLK_DOWN:
				sqry_vel = 1;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			//handle key releases (stop movement)
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				if (sqrx_vel < 0) {
					sqrx_vel = 0;
				}
				break;
			case SDLK_RIGHT:
				if (sqrx_vel > 0) {
					sqrx_vel = 0;
				}
				break;
			case SDLK_UP:
				if (sqry_vel < 0) {
					sqry_vel = 0;
				}
				break;
			case SDLK_DOWN:
				if (sqry_vel > 0) {
					sqry_vel = 0;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

}

void clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

void handleEvents() {
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
	}
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, SDL_WINDOW_SHOWN);

		if (window != 0) {

			running = true;
			renderer = SDL_CreateRenderer(window, -1, 0);

		}

	}
	else {

		return 1;

	}

	while (running) {

		//check to see if user exits
		handleEvents();
		if (!running) {
			clean();
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderClear(renderer);

		//The red square shows up
		SDL_Rect filledSqr = { sqrx, sqry, 10, 10 };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &filledSqr);

		SDL_RenderPresent(renderer);

	}

	return 0;
}