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

	virtual void Event(SDL_Event event);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Update();

	virtual bool Load();
	virtual bool Unload();

	std::string ToString();
private:
	std::string string;

protected:
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<SpriteManager> spriteManager;

};

#endif
