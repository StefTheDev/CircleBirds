#include "GameScene.h"

GameScene::GameScene() : Scene("Game Scene")
{

}

GameScene::~GameScene()
{

}

bool GameScene::Load()
{
	world = new b2World(b2Vec2{ 0.0f, 9.8f });

	std::shared_ptr<Platform> platform = std::make_shared<Platform>();
	platform->Load(spriteManager->Texture(PLATFORM_ICE_SPRITE), Vector2{ 0, 0});
	entities.emplace_back(platform);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->Load(spriteManager->Texture(PLAYER_RED_SPRITE), Vector2{ 60, 60 });
	entities.emplace_back(player);

	return Scene::Load();
}


void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}

