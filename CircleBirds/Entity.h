#pragma once

#include "Sprite.h"
class Entity
{
public:
	Entity(SDL_Rect rect, SDL_Texture* texture);
	~Entity();

	virtual void Render(SDL_Renderer * renderer);
	virtual void Listen(SDL_Event event) {}
	virtual void Update();

	void Texture(SDL_Texture* texture);

protected:
	SDL_Texture* texture = nullptr;
	float angle = 0.0f;
	SDL_Rect source, destination;
};
