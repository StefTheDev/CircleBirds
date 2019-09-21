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
	platform->Texture(textureManager->GetTexture(PLATFORM_ICE_SPRITE));
	platform->Load(SDL_Rect{ 0, 0, 64, 64 });


	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->Texture(textureManager->GetTexture(PLAYER_RED_SPRITE));
	player->Load(SDL_Rect{ 60, 60, 64, 64 });

	entities.push_back(player);
	entities.push_back(platform);

	return Scene::Load();
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}

