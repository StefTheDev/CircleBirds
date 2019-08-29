#pragma once

#ifndef PLAYER_H
#define PLAYER_H 

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	bool Initialise(Vector2 position) override;
	void Listen(SDL_Event event) override;
	void Update() override;
	void Render() override;

private:
	int mouseX, mouseY;
	SDL_GameController* gameController;
};
#endif 



