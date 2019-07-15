#include "Rect.h"//include rect header file (for creating squares/rectangles)
#include<iostream>//allow console output
#include<SDL_image.h>//allow IMG functions from SDL

//Rect constructor for use with a color
Rect::Rect(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a) :
	Window(window), m_w(w), m_h(h), m_x(x), m_y(y), m_r(r), m_g(g), m_b(b), m_a(a)
{

}

//Rect constructor for use with images
Rect::Rect(const Window &window, int w, int h, int x, int y, const std::string &img) :
	Window(window), m_w(w), m_h(h), m_x(x), m_y(y)
{
}

//Draw function draws the rectangle when called
void Rect::draw() const {
	if (m_texture) {
		//this is supposed to draw a rectangle with an image in it, but it doesn't work yet.
		SDL_Rect background = {m_x, m_y, m_w, m_h};
		SDL_RenderCopy(m_renderer, m_texture, nullptr, &background);
	}
	else {
		//draw colored square
		SDL_Rect rect = { m_x, m_y, m_w, m_h };
		SDL_SetRenderDrawColor(m_renderer, m_r, m_g, m_b, m_a);
		SDL_RenderFillRect(m_renderer, &rect);
	}

}


//allows the square to move around the window
void Rect::pollEvents(SDL_Event &event) {
	
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			std::cout << "Left arrow pressed" << std::endl;
			if ((m_x - 5) <= 0) {
				m_x = 0;//doesn't let the square leave the window
			}
			else {
				m_x -= 5;//allows the square to move
			}
			break;
		case SDLK_RIGHT:
			std::cout << "Right arrow pressed" << std::endl;
			if (m_x + 5 >= 790) {
				m_x = 790;//doesn't let the square leave the window
			}
			else {
				m_x += 5;//allows the square to move
			}
			break;
		case SDLK_DOWN:
			std::cout << "Down arrow pressed" << std::endl;
			if (m_y + 5 >= 440) {
				m_y = 440;//doesn't allow the square to leave window
			}
			else {
				m_y += 5;//allows square to move
			}
			break;
		case SDLK_UP:
			std::cout << "Up arrow pressed" << std::endl;
			if (m_y - 5 <= 0) {
				m_y = 0;//doesn't allow square to leave window
			}
			else {
				m_y -= 5;//allows square to move
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