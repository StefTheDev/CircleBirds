#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	bool Initialise();

private:
	SDL_Surface* menus;
	std::vector<std::string> labels;
};

