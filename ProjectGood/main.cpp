#include<iostream>//allow console output
#include<SDL.h>//include SDL funcitons
#include"Window.h"//include window header file for window functions
#include"Rect.h"//include rect header file for rect functions

//allow events for the window and rectangle separately
//doesn't allow either to cancel the other out like before
void pollEvents(Window& window, Rect& rect) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		window.pollEvents(event);
		rect.pollEvents(event);
	}
}

//main function
int main(int argc, char* argv[]) {
	Window window("Good Code", 800, 450);
	Rect rect(window, 10, 10, 10, 10, 255, 0, 0, 255);
	Rect obstacle(window, 100, 100, 350, 175, 0, 0, 0, 255);

	while (!window.isClosed()) {//while the program is running
		pollEvents(window, rect);//allows events for window and square
		rect.draw();//draw the square
		obstacle.draw();
		window.clear();//render graphics
	}

	return 0;//success
}