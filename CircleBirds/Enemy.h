#pragma once

#include "PhysicsEntity.h"

class Player : public PhysicsEntity
{
public:
	Player(b2World& _world, SDL_Rect _rect, b2Vec2 initialForce);
	~Player();

	void Update() override;

private:
	int mouseX, mouseY;
	b2Body* body;
};