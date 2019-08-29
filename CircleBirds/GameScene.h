#pragma once
#include "Scene.h"
#include "Level.h"

enum LevelType {
	BEGINNER_LEVEL,
	INTERMEDIATE_LEVEL
};

//Levels

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Initialise();

	void Update() override;
	void Render() override;

private:

	std::vector<std::unique_ptr<Level>> levels;

	LevelType levelType;
};

