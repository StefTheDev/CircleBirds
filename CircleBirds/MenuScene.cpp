#include "MenuScene.h"

MenuScene::MenuScene() : Scene("Menu")
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Initialise(SDL_Renderer * renderer)
{
	std::vector<std::shared_ptr<Entity>> entities;
	return Scene::Initialise(renderer, entities);
}
