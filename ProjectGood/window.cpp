#include "Window.h"//include window header file
#include<iostream>//allow output to console
#include<SDL.h>//allow SDL functions
#include<SDL_image.h>//allow SDL IMG functions

//window constructor (accepts title, width and height)
Window::Window(const std::string& title, int width, int height) :
	m_title(title), m_width(width), m_height(height) 
{
	m_closed = !init();//if initialization fails, close program
}

//Window destructor: destroys everything, and quits the program
Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	IMG_Quit();
	SDL_Quit();
}

//initialization function
bool Window::init() {
	//initialize everything in SDL, or output an error
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to initialize SDL" << std::endl;
		return false;
	}

	//initialize png image functions, or output error
	if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG) {
		std::cerr << "Failed to initialize IMG/PNG" << std::endl;
		return false;
	}

	//create window
	m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
	if (m_window == nullptr) {
		std::cerr << "Failed to create window" << std::endl;
		return false;
	}

	
	//create renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr) {
		std::cerr << "Failed to create renderer" << std::endl;
		return false;
	}

	return true;
}

//pollEvents for window
void Window::pollEvents(SDL_Event &event) {
	
	switch (event.type) {
	case SDL_QUIT://for the close button
		std::cout << "Window closed" << std::endl;
		m_closed = true;
		break;
	default:
		break;
	}
}

//clear function is what renders the basic blank window of specified color
void Window::clear() const {
	SDL_RenderPresent(m_renderer);//render present shows what is being rendered
	SDL_SetRenderDrawColor(m_renderer, 230, 230, 175, 255);//renders blank black screen
	SDL_RenderClear(m_renderer);
}