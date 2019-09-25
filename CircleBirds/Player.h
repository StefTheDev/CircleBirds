#pragma once

#include "PhysicsEntity.h"

class Player : public PhysicsEntity
{
public:
	Player(b2World& _world, EntityType entityType, SDL_Rect _rect, bool isStatic, b2Vec2 initialForce, SDL_Texture* texture);
	~Player();

	void Update() override;

private:
	int mouseX, mouseY;
	b2Body* body;
};



