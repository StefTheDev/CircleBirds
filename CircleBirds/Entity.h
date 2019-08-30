#pragma once

#include "Sprite.h"
class Entity
{
public:
	Entity();
	~Entity();

	virtual void Load(SDL_Texture * texture, Vector2 position);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Listen(SDL_Event event) {}
	virtual void Update();

	void Transform(Vector2 position);
	void Rotate(float angle);

private:
	float angle;

	Vector2 position;

	SDL_Texture * texture;
	SDL_Rect source, destination;
};
