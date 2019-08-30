#pragma once
#include "Entity.h"

class TextLabel : public Entity
{
public:
	~TextLabel();

	void Listen(SDL_Event event) override;

private:
	int mouseX, mouseY;

	SDL_Surface * screen;
	TTF_Font * font;
	SDL_Color colors[2] = {{ 255, 255, 255 }, { 255, 255, 0 }};
};

