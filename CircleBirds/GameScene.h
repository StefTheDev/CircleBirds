#pragma once

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"
#include "Player.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	bool Initialise(SDL_Renderer* renderer);
};


#endif

