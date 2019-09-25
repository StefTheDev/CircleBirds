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

	std::shared_ptr<Entity> background = std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 });
	background->Texture(textureManager->GetTexture(BACKGROUND_SPRITE));
	entities.push_back(background);

	std::shared_ptr<PhysicsEntity> ground = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 0, 680, 1280, 120 }, true);
	ground->Texture(textureManager->GetTexture(GROUND_SPRITE));
	entities.push_back(ground);

	std::shared_ptr<Entity> catapult = std::make_shared<Entity>(SDL_Rect{ 160, 420, 64, 159 });
	catapult->Texture(textureManager->GetTexture(CATAPULT_SPRITE));
	entities.push_back(catapult);
	

	std::shared_ptr<PhysicsEntity> platform = std::make_shared<PhysicsEntity>(*world, CIRCLE_ENTITY, SDL_Rect{ 500, 400, 32, 32 }, true);
	platform->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));
	entities.push_back(platform);

	std::shared_ptr<PlayerHandler> playerHandler = std::make_shared<PlayerHandler>(SDL_Rect{64, 536, 64, 64}, world, std::shared_ptr<Scene>(this));
	playerHandler->Texture(textureManager->GetTexture(PLAYER_RED_SPRITE));
	entities.push_back(playerHandler);

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			std::shared_ptr<PhysicsEntity> box = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ (32 * x) + 800, (y % 32) + 400, 32, 32 }, false);
			box->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));
			entities.push_back(box);
		}
	}

	b2Body* link = platform->GetBody();
	b2Body* newLink = nullptr;

	for (int i = 0; i < 5; i++)
	{
		std::shared_ptr<PhysicsEntity> ice_cube = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 16 * i, 16 * i, 32, 32 }, false);
		ice_cube->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));

		b2RevoluteJointDef revoluteJointDef;
		if (i == 0) {
			revoluteJointDef.localAnchorA.Set(0, 0);
			revoluteJointDef.localAnchorB.Set(0, 0);
		}
		else {
			revoluteJointDef.localAnchorA.Set(0.15, 0);
			revoluteJointDef.localAnchorB.Set(-0.15, 0);
		}

		newLink = ice_cube->GetBody();
		revoluteJointDef.bodyA = link;
		revoluteJointDef.bodyB = newLink;
		world->CreateJoint(&revoluteJointDef);

		link->SetLinearDamping(1.0f);
		link = newLink;

		entities.push_back(ice_cube);
	}

	return Scene::Load();
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
