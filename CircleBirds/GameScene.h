#pragma once
#include "Scene.h"
#include "Player.h"
#include "Platform.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Load() override;
	void Update() override;

private:
	b2World * world;
};

