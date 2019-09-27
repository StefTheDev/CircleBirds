#include "Sprite.h"

Sprite::Sprite(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

Sprite::~Sprite()
{

}

bool Sprite::LoadImageFromFile(std::string fileName)
{
	texture = IMG_LoadTexture(renderer, fileName.c_str());
	return texture != nullptr;
}

bool Sprite::LoadText(std::string text, TTF_Font* font, SDL_Color color)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (surface == nullptr) return false;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture != nullptr;
}

void Sprite::SetColor(SDL_Color color)
{
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

SDL_Texture* Sprite::GetTexture()
{
	return texture;
}
