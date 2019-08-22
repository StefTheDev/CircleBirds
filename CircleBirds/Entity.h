#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialise(std::shared_ptr<Sprite> sprite);
	virtual void Render();
	virtual void Update();

	void Transform(Vector2 position);
	void Rotate(float angle);

private:

	Vector2 position;
	float angle;

	std::shared_ptr<Sprite> sprite;
	SDL_Rect source, destination;
};

#endif
