#pragma once
#include "Entity.h"
class PhysicsEntity : public Entity
{
public:
	PhysicsEntity(b2World& _world, SDL_Rect _rect, bool isStatic);
	void Update() override;

protected:
	b2Body* body;

};

