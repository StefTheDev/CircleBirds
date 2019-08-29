#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	bool Initialise(SDL_Renderer * renderer, Vector2 position);
	void Update() override;
	void Render() override;

	void Event(SDL_Event event) override;

private:
	int mouseX, mouseY;
	SDL_GameController* gameController;
};



