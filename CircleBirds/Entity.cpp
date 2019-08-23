#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

bool Entity::Initialise(std::shared_ptr<Sprite> sprite, Vector2 position)
{
	this->sprite = sprite;
	this->position = position;
	this->angle = 0.0f;

	source.x = source.y = 0;
	source.w = source.h = 64;
	destination.w = destination.h = 64;

	return true;
}

void Entity::Render()
{
	SDL_RenderCopyEx(
		sprite->GetRenderer(), 
		sprite->GetTexture(),
		&source,
		&destination,
		angle,
		NULL,
		SDL_FLIP_NONE
	
	);
}

void Entity::Update()
{
	destination.x = (int) position.x;
	destination.y = (int) position.y;
}

void Entity::Event(SDL_Event event)
{

}

void Entity::Transform(Vector2 position)
{
	this->position += position;
}

void Entity::Rotate(float angle)
{
	this->angle += angle;
}
