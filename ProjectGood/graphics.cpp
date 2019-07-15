#include"Rect.h"
#include"Graphics.h"//include the Graphics header file
#include<iostream>
#include<string>

Graphics::Graphics(const Rect &rect, const std::string& path) :
	Rect(rect), m_path(path)
{
	//load the image from surface
	SDL_Surface* surface = IMG_Load(path.c_str());
	//create texture from surface
	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	//set height and width of the picture destination based on surface
	m_destRect.w = surface->w;
	m_destRect.h = surface->h;
	//get rid of the surface/free memory
	SDL_FreeSurface(surface);
}

Graphics::~Graphics() {
	SDL_DestroyTexture(m_texture);
}

void Graphics::Render(SDL_Renderer* renderer) const
{
	SDL_RenderCopy(renderer, m_texture, NULL, &m_destRect);
}