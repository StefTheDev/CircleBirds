#pragma once

#include "Entity.h"

class Level
{
public:
	Level();
	~Level();

	bool Initialise(b2Vec2 gravity, std::vector<std::shared_ptr<Entity>>& entities);

	virtual void Render();
	virtual void Update();
	virtual void Listen(SDL_Event event);


private:
	b2World * world;

	std::vector<std::shared_ptr<Entity>> entities;
};

