#pragma once
#include "Scene.h"

//Entities
#include "Pig.h"
#include "PlayerHandler.h"

//Materials
#include "StoneBrick.h"
#include "WoodPlank.h"

class GameScene2 : public Scene
{
public:
	GameScene2();
	~GameScene2();

	bool Load() override;
	void Update() override;
private:
	b2World* world;
	std::vector<Entity> birds;
};

