#pragma once

#include "Sprite.h"
class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Load(SDL_Rect rect);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Listen(SDL_Event event) {}
	virtual void Update();

	void Texture(SDL_Texture * texture);

protected:
	SDL_Texture* texture = nullptr;
	Vector2 position;
	float angle = 0.0f;
	SDL_Rect source, destination;
};
