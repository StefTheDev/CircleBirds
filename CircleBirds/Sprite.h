#pragma once
#include "Utilities.h"

class Sprite
{
public:
	Sprite(SDL_Renderer * renderer);
	~Sprite();

	bool LoadImageFromFile(std::string fileName);
	bool LoadText(std::string text, TTF_Font* font, SDL_Color color);

	void SetColor(SDL_Color color);

	SDL_Renderer* renderer;
	SDL_Texture * GetTexture();

private:
	SDL_Texture * texture = nullptr;
	int width, height;
};


