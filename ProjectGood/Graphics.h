#pragma once
#include "Rect.h"
#include<string>
#include<SDL_image.h>

class Graphics : public Window //Graphics inherits from Rect, which inherits from Window
{
public:
	Graphics(Window window, const std::string& path);//constructor
	~Graphics();//destructor

	void Render(Window window) const;

private:

protected:
	SDL_Rect* m_destRect;//destination rectangle
	SDL_Texture* m_texture;//texture for texture from surface

};