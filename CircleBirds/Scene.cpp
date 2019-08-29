#include "Scene.h"
#include "Entity.h"

Scene::Scene(std::string string)
{
	this->string = string;
}

Scene::~Scene()
{
}

bool Scene::Initialise(SDL_Renderer * renderer, std::vector<std::shared_ptr<Entity>>& entities)
{
	this->renderer = renderer;
	this->entities = entities;

	std::cout << string.c_str() << " Initialised" << std::endl;

	return true;
}

void Scene::Event(SDL_Event event)
{
	for (auto& entity : entities) {
		entity->Listen(event);
	}
}

void Scene::Render()
{
	for (auto& entity : entities) {
		entity->Render();
	}
}

void Scene::Update()
{
	for (auto& entity : entities) {
		entity->Update();
	}
}

std::string Scene::ToString()
{
	return string;
}
