#include"Window.h"
#include"Graphics.h"//include the Graphics header file
#include<iostream>
#include<string>

Graphics::Graphics(Window window, const std::string& path)
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

void Graphics::Render(Window window) const
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_destRect);
}