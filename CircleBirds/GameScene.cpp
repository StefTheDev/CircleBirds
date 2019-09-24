#include "GameScene.h"

GameScene::GameScene() : Scene("Game Scene")
{
	world = new b2World(b2Vec2{ 0.0f, 9.8f });
}

GameScene::~GameScene()
{

}

bool GameScene::Load()
{

	std::shared_ptr<Entity> background = std::make_shared<Entity>(SDL_Rect{ 0, 0, 1600, 800 });
	background->Texture(textureManager->GetTexture(BACKGROUND_SPRITE));
	

	std::shared_ptr<PhysicsEntity> platform = std::make_shared<PhysicsEntity>(*world, SDL_Rect{ 0, 600, 1600, 200 }, true);
	platform->Texture(textureManager->GetTexture(PLATFORM_ICE_SPRITE));

	std::shared_ptr<Player> player = std::make_shared<Player>(*world, SDL_Rect{ 60, 60, 64, 64 });
	player->Texture(textureManager->GetTexture(PLAYER_RED_SPRITE));

	entities.push_back(background);
	entities.push_back(player);
	entities.push_back(platform);

	return Scene::Load();
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}

