#pragma once

#include "Utilities.h"

const int WINDOW_WIDTH = 1280;
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
	virtual b2World* GetWorld() { return nullptr; };
	virtual bool Load();
	virtual bool Unload();

	void AddEntity(std::shared_ptr<Entity> _entity);

	std::vector<std::shared_ptr<Entity>> entities;

	std::string ToString();

private:
	std::string string;

protected:


};

