#include "GameScene2.h"



GameScene2::GameScene2() : Scene("Game Scene 2")
{
	world = new b2World(b2Vec2{ 0.0f, 3.2f });
}


GameScene2::~GameScene2()
{
}

bool GameScene2::Load()
{
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 }, textureManager->GetTexture(BACKGROUND_SPRITE)));

	std::shared_ptr<PhysicsEntity> ground = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 0, 680, 1280, 120 }, true, textureManager->GetTexture(GROUND_SPRITE));
	entities.push_back(ground);

	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 550, 32, 80 }, textureManager->GetTexture(CATAPULT_SPRITE)));
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 630, 48, 48 }, textureManager->GetTexture(WOOD_PLANK_SPRITE)));

	entities.push_back(std::make_shared<PlayerHandler>(SDL_Rect{ 64, 536, 32, 32 }, world, std::shared_ptr<Scene>(this), textureManager->GetTexture(PLAYER_RED_SPRITE)));

	return Scene::Load();
}

void GameScene2::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
