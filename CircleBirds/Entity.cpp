#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Load(SDL_Texture * texture, Vector2 position)
{
	this->texture = texture;
	this->position = position;

	source.x = source.y = 0;
	source.w = source.h = 64;
	destination.w = destination.h = 64;
}

void Entity::Render(SDL_Renderer * renderer)
{
	SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, NULL, SDL_FLIP_NONE);
}

void Entity::Update()
{
	destination.x = (int) position.x;
	destination.y = (int) position.y;
}

void Entity::Transform(Vector2 position)
{
	this->position += position;
}

void Entity::Rotate(float angle)
{
	this->angle += angle;
}
