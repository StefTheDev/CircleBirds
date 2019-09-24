#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(SDL_Rect _rect, b2World& _world);
	~Player();

	void Listen(SDL_Event event) override;
	void Update() override;

private:
	int mouseX, mouseY;
	b2Body* body;
};



