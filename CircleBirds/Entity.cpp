#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

bool Entity::Initialise(std::shared_ptr<Sprite> sprite)
{
	this->sprite = sprite;
	this->position = std::make_unique<Vector2>();

	source.x = source.y = 0;
	source.w = source.h = 32;
	destination.w = destination.h = 64;

	return true;
}

void Entity::Render()
{
	SDL_RenderCopy(
		sprite->GetRenderer(), 
		sprite->GetTexture(), 
		&source, 
		&destination
	);
}

void Entity::Update()
{
	destination.x = (int) position->GetX();
	destination.y = (int) position->GetY();
}
