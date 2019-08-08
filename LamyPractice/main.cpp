#include<iostream>//allow console output
#include<SDL.h>//include SDL funcitons
#include"Window.h"//include window header file for window functions
#include"PlayObjs.h"//include player objects header file for rect functions
#include "Tiles.h"

Window window("Lamy", 800, 450);//window

//dimensions of tiles
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

//dimensions of level
const int LEVEL_WIDTH = 1024;
const int LEVEL_HEIGHT = 576;
const int TOTAL_TILES = 576;

//dimensions of screen
const int SCREEN_WIDTH = window.getWidth();
const int SCREEN_HEIGHT = window.getHeight();

//tile types
const int OPEN = 0;
const int OPEN_DOOR = 1;
const int CLOSED_DOOR = 2;
const int WALL = 3;

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
	Tiles* tileSet[ TOTAL_TILES ];
	PlayObjs player(window, 20, 20, 100, 100, true, 255, 0, 0, 255);//red square

	while (!window.isClosed()) {//while the program is running
		pollEvents(window, player);//allows events for window and square
		window.drawBGImg("images/background.jpg");//load background image
		player.drawColor();//draw player square (red square)
		window.clear();//draw background image
		//***********Whole window ends up red right now. **********WORK ON THIS
	}

	return 0;//success
}