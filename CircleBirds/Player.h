#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	bool Initialise(Vector2 position) override;
	void Listen(SDL_Event event) override;
	void Update() override;

private:
	int mouseX, mouseY;
};



