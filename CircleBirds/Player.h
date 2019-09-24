#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(b2World& _world, SDL_Rect _rect);
	~Player();

	void Listen(SDL_Event event) override;
	void Update() override;

private:
	int mouseX, mouseY;
	b2Body* body;
};



