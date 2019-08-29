#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "SpriteManager.h"

class Entity;

class Scene
{
public:
	Scene(std::string string);
	~Scene();

	virtual bool Initialise(std::vector<std::shared_ptr<Entity>> entities);
	virtual void Event(SDL_Event event);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Update();

	std::string ToString();

private:
	std::vector<std::shared_ptr<Entity>> entities;
	std::string string;

};

#endif
