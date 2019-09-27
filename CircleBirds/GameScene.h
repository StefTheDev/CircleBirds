#pragma once
#include "Scene.h"

//UI
#include "TextLabel.h"

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
	b2World* GetWorld() override { return world; };
	void GenerateTower(int xOffset, int yOffset);

private:
	b2World * world = nullptr;
	std::vector<Entity> birds;
};

