#include "Scene.h"

Scene::Scene(std::string string)
{
	this->string = string;
}

Scene::~Scene()
{
}

bool Scene::Initialise()
{
	std::cout << string.c_str() << " Initialised" << std::endl;
	return true;
}

void Scene::Render()
{
}

void Scene::Update()
{
}

std::string Scene::ToString()
{
	return string;
}
