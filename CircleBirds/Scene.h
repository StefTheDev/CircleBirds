#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Utilities.h"

class Entity;

class Scene
{
public:
	Scene(std::string string);
	~Scene();

	virtual bool Initialise(SDL_Renderer * renderer, std::vector<std::shared_ptr<Entity>>& entities);
	virtual void Render();
	virtual void Update();

	std::string ToString();

private:
	std::vector<std::shared_ptr<Entity>> entities;
	std::string string;

	SDL_Renderer * renderer;
};

#endif
