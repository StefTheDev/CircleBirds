#pragma once
#include "Scene.h"
#include "Player.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Initialise();

	void Update() override;

private:
	b2World * world;
};

