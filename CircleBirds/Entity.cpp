#include "Entity.h"

Entity::Entity(SDL_Rect rect, SDL_Texture* texture)
{
	this->texture = texture;

	source.x = source.y = 0;
	source.w = rect.w;
	source.h = rect.h;

	destination.x = rect.x;
	destination.y = rect.y;
	destination.w = rect.w;
	destination.h = rect.h;
}

Entity::~Entity()
{
	SDL_DestroyTexture(texture);
}

void Entity::Render(SDL_Renderer * renderer)
{
	SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, NULL, SDL_FLIP_NONE);
}

void Entity::Update()
{

}

void Entity::SetAngle(float angle)
{
	this->angle = angle;
}

void Entity::Texture(SDL_Texture* texture)
{
	this->texture = texture;
}
