#pragma once
#include "Scene.h"

//Entities
#include "Pig.h"
#include "PlayerHandler.h"

//Materials
#include "StoneBrick.h"
#include "WoodPlank.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Load() override;
	void Update() override;

	void GenerateTower(int xOffset, int yOffset);

private:
	b2World * world;
	std::vector<Entity> birds;
};

