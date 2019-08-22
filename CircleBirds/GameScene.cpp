#include "GameScene.h"

GameScene::GameScene() : Scene("Game")
{

}

GameScene::~GameScene()
{

}

bool GameScene::Initialise(SDL_Renderer* renderer)
{
	std::vector<std::shared_ptr<Entity>> entities;

	std::shared_ptr<Player> player = std::make_shared<Player>();
	if (!player->Initialise(renderer, Vector2{ 10.0f, 50.0f})) return false;

	entities.push_back(player);

	//Enemies
	//Obstacles

	return Scene::Initialise(renderer, entities);
}
