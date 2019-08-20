#pragma once

#ifndef PLAYER_H
#define PLAYER_H 

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	bool Initialise(SDL_Renderer * renderer);
	void Update() override;
	void Render() override;

private:
	
	SDL_GameController* gameController;
};
#endif 



