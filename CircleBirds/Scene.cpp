#include "Scene.h"
#include "Entity.h"

Scene::Scene(std::string string)
{
	this->string = string;
}

Scene::~Scene()
{
}

bool Scene::Initialise(std::vector<std::shared_ptr<Entity>> entities)
{
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

void Scene::Render(SDL_Renderer * renderer)
{
	for (auto& entity : entities) {
		entity->Render(renderer);
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
