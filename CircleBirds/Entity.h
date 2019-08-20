#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include "Vector2.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialise(std::shared_ptr<Sprite> sprite);
	virtual void Render();
	virtual void Update();

private:
	std::shared_ptr<Sprite> sprite;
	std::unique_ptr<Vector2> position;
	SDL_Rect source, destination;
};

#endif
