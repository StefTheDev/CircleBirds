#pragma once

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Initialise() override;
	void Render() override;
	void Update() override;
};


#endif

