#pragma once
#include "Scene.h"
#include "Player.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Initialise(SDL_Renderer* renderer);
};

