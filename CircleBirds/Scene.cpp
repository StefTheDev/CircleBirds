#include "Scene.h"
#include "Entity.h"

Scene::Scene(std::string string)
{
	this->string = string;


	textureManager = TextureManager::GetInstance();
}

Scene::~Scene()
{

}

void Scene::Listen(SDL_Event event)
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

bool Scene::Load()
{
	std::cout << ToString().c_str() << " Loaded Successfully" << std::endl;
	return true;
}

bool Scene::Unload()
{
	if (entities.empty()) return true;
	entities.clear();
	return true;
}

std::string Scene::ToString()
{
	return string;
}
