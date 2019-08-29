#include "Sprite.h"

Sprite::Sprite(const char * fileName, SDL_Renderer * renderer)
{
	texture = IMG_LoadTexture(renderer, fileName);
	if (texture == nullptr) { std::cout << "Texture at "<< fileName << " is null" << std::endl; }
}

Sprite::~Sprite()
{

}

SDL_Texture * Sprite::GetTexture()
{
	return texture;
}
