#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(SDL_Rect rect);
	~Player();

	void Listen(SDL_Event event) override;
	void Update() override;

private:
	int mouseX, mouseY;
};



