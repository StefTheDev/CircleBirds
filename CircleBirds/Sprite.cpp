#include "Sprite.h"

Sprite::Sprite(const char * fileName, SDL_Renderer * renderer)
{
	this->renderer = renderer;
	texture = IMG_LoadTexture(renderer, fileName);
	if (texture == nullptr) { std::cout << "Texture is null" << std::endl; }
}

Sprite::~Sprite()
{

}

SDL_Texture * Sprite::GetTexture()
{
	return texture;
}

SDL_Renderer * Sprite::GetRenderer()
{
	return renderer;
}
