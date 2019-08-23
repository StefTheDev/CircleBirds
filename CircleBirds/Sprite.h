#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Utilities.h"

class Sprite
{
public:
	Sprite(const char * fileName, SDL_Renderer * renderer);
	~Sprite();

	SDL_Texture * GetTexture();
	SDL_Renderer * GetRenderer();

private:
	SDL_Texture * texture;
	SDL_Renderer * renderer;
};

#endif 


