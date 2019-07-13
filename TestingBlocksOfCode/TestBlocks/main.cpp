#include<SDL.h>
#include<SDL_keycode.h>
#include<iostream>

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
			case SDLK_LEFT://what happens when left arrow key is pressed
				sqrx_vel = -5;//set the velocity to 5
				std::cout << "Left key pressed" << std::endl;//document key press
				break;
			case SDLK_RIGHT://what happens when right arrow key is pressed
				sqrx_vel = 5;//set the velocity to 5
				std::cout << "Right key pressed" << std::endl;//document key press
				break;
			case SDLK_UP://what happens when up arrow key is pressed
				sqry_vel = -5;//set velocity to 5
				std::cout << "Up key pressed" << std::endl;//document key press
				break;
			case SDLK_DOWN://what happens when down arrow key is pressed
				sqry_vel = 5;//change the velocity to 5
				std::cout << "Down key pressed" << std::endl;//document key press
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			//handle key releases (stop movement)
			switch (event.key.keysym.sym) {
			case SDLK_LEFT://what happens when left arrow key is released
				std::cout << "Left key released" << std::endl;//document key release
				if (sqrx_vel < 0) {//if the square is moving
					sqrx_vel = 0;//set velocity back to 0
				}
				break;
			case SDLK_RIGHT://what happens when right key is released
				std::cout << "Right key released" << std::endl;//document key release
				if (sqrx_vel > 0) {//if the square is moving
					sqrx_vel = 0;//set velocity back to 0
				}
				break;
			case SDLK_UP://what happens when up key is released
				std::cout << "up key released" << std::endl;//document key release
				if (sqry_vel < 0) {//if the square is moving
					sqry_vel = 0;//set velocity back to 0
				}
				break;
			case SDLK_DOWN://what happens when down key is released
				std::cout << "down key released" << std::endl;//document key release
				if (sqry_vel > 0) {//if the square is moving
					sqry_vel = 0;//set velocity back to 0
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

void clean() {//clean up the program and close

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

void handleEvents() {
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT://if the program is closed by user
			running = false;//stop running
			break;
		default:
			break;
		}
	}
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {//initialize everything

		window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, SDL_WINDOW_SHOWN);//make window

		if (window != 0) {//if the window creation was successful

			running = true;//let the game know it is running
			renderer = SDL_CreateRenderer(window, -1, 0);//create renderer

		}

	}
	else {

		return 1;//initialization fail

	}

	while (running) {//while the program is running

		//check to see if user exits
		handleEvents();
		if (!running) {
			clean();//clean up program and close if the user exits
			break;
		}
		checkKeys();//check for key presses/releases
		//change square position variables based on velocity
		sqrx = sqrx + sqrx_vel;//change x position
		sqry = sqry + sqry_vel;//change y position

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//render black background

		SDL_RenderClear(renderer);//clear window

		//The red square shows up
		SDL_Rect filledSqr = { sqrx, sqry, 10, 10 };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &filledSqr);

		SDL_RenderPresent(renderer);//render everything to screen

	}

	return 0;//success
}