#include "MenuScene.h"

MenuScene::MenuScene() : Scene("Menu")
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Initialise()
{
	std::vector<std::shared_ptr<Entity>> entities;

	return Scene::Initialise(entities);
}
