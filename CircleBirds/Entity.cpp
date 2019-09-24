#include "Entity.h"

Entity::Entity(SDL_Rect rect)
{

	position.x = static_cast<float>(rect.x);
	position.y = static_cast<float>(rect.y);

	source.x = source.y = 0;
	source.w = rect.w;
	source.h = rect.h;

	destination.w = source.w;
	destination.h = source.h;
}

Entity::~Entity()
{
	SDL_DestroyTexture(texture);
}

bool Entity::Load(SDL_Rect rect)
{
	this->position = Vector2{ 
		static_cast<float>(rect.x),
		static_cast<float>(rect.y),
	};

	source.x = source.y = 0;
	source.w = rect.w;
	source.h = rect.h;

	destination.w = source.w;
	destination.h = source.h;
	return true;
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

void Entity::Texture(SDL_Texture * texture)
{
	this->texture = texture;
}
