#pragma once
#include "PhysicsEntity.h"

class DestructibleEntity : public PhysicsEntity
{

public:
	DestructibleEntity(b2World& _world, EntityType entityType, SDL_Rect _rect, SDL_Texture* texture, float health);
	bool dealDamage(float damage);
private:
	float health;
};

