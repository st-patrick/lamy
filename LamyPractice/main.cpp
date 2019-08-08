#include<iostream>//allow console output
#include<SDL2/SDL.h>//include SDL funcitons
#include"Window.h"//include window header file for window functions
#include"PlayObjs.h"//include player objects header file for rect functions

//allow events for the window and rectangle separately
//doesn't allow either to cancel the other out like before
void pollEvents(Window& window, PlayObjs& player) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		window.pollEvents(event);
		player.pollEvents(event);
	}
}

//main function
int main(int argc, char* argv[]) {
	Window window("Lamy", 800, 450);//window
	//Rect rect(window, 10, 10, 10, 10, 255, 0, 0, 255);//red square
	//Rect obstacle(window, 100, 100, 350, 175, 0, 0, 0, 255);//big obstacle block

	while (!window.isClosed()) {//while the program is running
		//pollEvents(window, rect);//allows events for window and square
		window.drawBGImg("images/background.jpg");//replace with tile map*****
		//rect.draw();//draw the square
		//obstacle.draw();//draw obstacle square
		window.clear();//draw background image
	}

	return 0;//success
}