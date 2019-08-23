#pragma once

#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	bool Initialise(SDL_Renderer * renderer);

private:
};

#endif

