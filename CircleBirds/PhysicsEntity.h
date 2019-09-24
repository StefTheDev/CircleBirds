#pragma once
#include "Entity.h"

enum EntityType {
	CIRCLE_ENTITY = 0,
	BOX_ENTITY
};

class PhysicsEntity : public Entity
{
public:
	PhysicsEntity(b2World& _world, EntityType entityType, SDL_Rect _rect, bool isStatic);
	void Update() override;

	b2Body* GetBody();

protected:
	b2Body* body;
};

