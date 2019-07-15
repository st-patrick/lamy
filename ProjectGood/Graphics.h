#pragma once
#include "Rect.h"
#include<string>
#include<SDL_image.h>

class Graphics : public Rect //Graphics inherits from Rect, which inherits from Window
{
public:
	Graphics(const Rect &rect, const std::string& path);//constructor
	~Graphics();//destructor

	void Render(SDL_Renderer* renderer) const;

private:
	SDL_Rect m_destRect;//destination rectangle
	SDL_Texture* m_texture;//texture for texture from surface
	std::string m_path;

protected:

};