#pragma once

#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialise(std::shared_ptr<Sprite> sprite, Vector2 position);
	virtual void Render();
	virtual void Update();
	virtual void Event(SDL_Event event);

	void Transform(Vector2 position);
	void Rotate(float angle);

private:

	Vector2 position;
	float angle;

	std::shared_ptr<Sprite> sprite;
	SDL_Rect source, destination;
};
