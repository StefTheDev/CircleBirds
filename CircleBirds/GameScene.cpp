#include "GameScene.h"

GameScene::GameScene() : Scene("Game")
{

}

GameScene::~GameScene()
{

}

bool GameScene::Initialise()
{
	return true;
}

void GameScene::Update()
{
	levels[levelType]->Update();
}

void GameScene::Render() 
{
	levels[levelType]->Render();
}
