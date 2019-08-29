#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();


	bool Initialise(SDL_Renderer * renderer);

private:
	SDL_Surface* menus;
	std::vector<std::string> labels;
};

