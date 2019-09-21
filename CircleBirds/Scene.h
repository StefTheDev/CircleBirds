#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "TextureManager.h"

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 800;

class Entity;

class Scene
{
public:
	Scene(std::string string);
	~Scene();

	virtual void Listen(SDL_Event event);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Update();

	virtual bool Load();
	virtual bool Unload();

	std::string ToString();

private:
	std::string string;

protected:
	std::vector<std::shared_ptr<Entity>> entities;

	std::shared_ptr<TextureManager> textureManager;
};

#endif
