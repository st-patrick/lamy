#pragma once
#include<string>//allow string functions
#include<SDL.h>//allow SDL functions

class Window {
public:
	//window constructor
	Window(const std::string& title, int width, int height);
	//window destructor
	~Window();

	//variable for the title of the window
	std::string m_title;

	//function to handle events (just close right now)
	void pollEvents(SDL_Event &event);

	//used for window rendering
	void clear() const;

	//tells the window whether to close and destruct or not
	inline bool isClosed() const { return m_closed; }

	//variable to indicate whether the window is closed by user
	bool m_closed = false;

private:

	bool init();//indicates successful/failed initialization

	//height and width of window
	int m_width = 800, m_height = 450;

	//window pointer
	SDL_Window* m_window = nullptr;

protected:
	//renderer pointer (protected so it can be used by classes that inherit from class window)
	SDL_Renderer* m_renderer = nullptr;
};