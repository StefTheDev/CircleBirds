#pragma once
#include "Scene.h"
#include "PhysicsEntity.h"
#include "PlayerHandler.h"

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

