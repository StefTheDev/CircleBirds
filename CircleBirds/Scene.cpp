#include "Scene.h"
#include "Entity.h"

Scene::Scene(std::string string)
{
	this->string = string;
}

Scene::~Scene()
{

}

void Scene::Listen(SDL_Event event)
{
	int entityCount = entities.size();
	for (int i = 0; i < entityCount; i++) {
		if (i < entities.size())  {
			entities[i]->Listen(event);
		}
	}
}

void Scene::Render(SDL_Renderer * renderer)
{
	int entityCount = entities.size();
	for (int i = 0; i < entityCount; i++) {
		if (i < entities.size()) {
			entities[i]->Render(renderer);
		}
	}
}

void Scene::Update()
{
	int entityCount = entities.size();
	for (int i = 0; i < entityCount; i++) {
		if (i < entities.size()) {
			entities[i]->Update();
		}
	}
}

bool Scene::Load()
{
	std::cout << ToString().c_str() << " Loaded Successfully" << std::endl;
	return true;
}

bool Scene::Unload()
{
	entities.clear();
	return true;
}

void Scene::AddEntity(std::shared_ptr<Entity> _entity)
{
	entities.push_back(_entity);
}

std::string Scene::ToString()
{
	return string;
}
