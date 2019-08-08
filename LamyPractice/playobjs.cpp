#include<iostream>
#include"PlayObjs.h"//include headerfile
#include<SDL.h>
#include<SDL_image.h>

//constructor for use with a color
PlayObjs::PlayObjs(const Window& window, int w, int h, int x, int y, bool primary, int r, int g, int b, int a) :
	Window(window), mw(w), mh(h), mx(x), my(y), mprimary(primary), mr(r), mg(g), mb(b), ma(a)
{

}

//constructor for use with an image
PlayObjs::PlayObjs(const Window& window, int w, int h, int x, int y, bool primary, std::string& path) :
	Window(window), mw(w), mh(h), mx(x), my(y), mprimary(primary), mpath(path)
{

}

//drawing the solid color object
void PlayObjs::drawColor() {
	SDL_Rect playObj = { mx, my, mw, mh };
	SDL_SetRenderDrawColor(m_renderer, mr, mg, mb, ma);
	SDL_RenderFillRect(m_renderer, &playObj);
}

//drawing the image object
void PlayObjs::drawImg() {
	SDL_Rect playDest = { mx, my, mw, mh };
	m_surface = IMG_Load(mpath.c_str());
	if (m_surface == nullptr) {
		std::cout << "Unable to load image" << std::endl;
	}
	else {
		m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
		SDL_FreeSurface(m_surface);
		if (m_texture == nullptr) {
			std::cout << "Unable to create texture" << std::endl;
		}
	}
	SDL_RenderCopy(m_renderer, m_texture, NULL, &playDest);
}

void PlayObjs::pollEvents(SDL_Event& event) {
	//right arrow, left arrow, up arrow, down arrow
	//x to grab objects
	//c to drop objects
}