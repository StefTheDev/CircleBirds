#include "GameScene.h"

GameScene::GameScene() : Scene("Game")
{

}

GameScene::~GameScene()
{

}

bool GameScene::Initialise()
{
	world = new b2World(b2Vec2{ 0.0f, 9.8f });

	std::shared_ptr<SpriteManager> spriteManager = SpriteManager::GetInstance();

	std::vector<std::shared_ptr<Entity>> entities;

	//TODO: Load entities (Blocks, Platforms) from file
	
	std::shared_ptr<Platform> platform = std::make_shared<Platform>();

	if (!platform->Initialise(Vector2{ 0.0f, 0.0f })) return false;
	platform->SetSprite(spriteManager->GetSprite(PLATFORM_ICE_SPRITE));

	entities.push_back(platform);

	std::shared_ptr<Player> player = std::make_shared<Player>();

	if (!player->Initialise(Vector2{ 0.0f, 0.0f })) return false;
	player->SetSprite(spriteManager->GetSprite(PLAYER_RED_SPRITE));

	entities.push_back(player);

	return Scene::Initialise(entities);
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	
	Scene::Update();
}
