#pragma once
#include "Window.h"//include window header file
#include<SDL2/SDL.h>//include SDL2
#include<string>//allow string functions

class Rect : public Window {//Rect inherits from window
public:
	//constructor for colored rectangle
	Rect(const Window& window, int w, int h, int x, int y, int r, int g, int b, int a);

	void draw() const;//draw function to display rectangles
	void pollEvents(SDL_Event& event);//handle rectangle events

private:
	//variables for width, height, position, and color
	int m_w, m_h, m_x, m_y, m_r, m_g, m_b, m_a;

protected:

};