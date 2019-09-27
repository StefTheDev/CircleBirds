#pragma once

#include "PhysicsEntity.h"

class Enemy : public PhysicsEntity
{
public:
	Enemy(b2World& _world, SDL_Rect _rect, SDL_Texture* texture);
	~Enemy();

private:
	int mouseX, mouseY;
	b2Body* body;
};