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

	std::shared_ptr<Entity> catapult = std::make_shared<Entity>(SDL_Rect{ 120, 550, 32, 80 });
	catapult->Texture(textureManager->GetTexture(CATAPULT_SPRITE));
	entities.push_back(catapult);
	

	std::shared_ptr<PlayerHandler> playerHandler = std::make_shared<PlayerHandler>(SDL_Rect{64, 536, 32, 32}, world, std::shared_ptr<Scene>(this));
	playerHandler->Texture(textureManager->GetTexture(PLAYER_RED_SPRITE));
	entities.push_back(playerHandler);

	std::shared_ptr<Entity> catapultPlatform = std::make_shared<Entity>(SDL_Rect{ 120, 630, 48, 48 });
	catapultPlatform->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));
	entities.push_back(catapultPlatform);


	std::shared_ptr<PhysicsEntity> plank = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 500, 580, 8, 100 }, false);
	plank->Texture(textureManager->GetTexture(PLANK_WOOD_SPRITE));
	entities.push_back(plank);

	std::shared_ptr<PhysicsEntity> plank2 = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 592, 580, 8, 100 }, false);
	plank2->Texture(textureManager->GetTexture(PLANK_WOOD_SPRITE));
	entities.push_back(plank2);

	std::shared_ptr<PhysicsEntity> plank3 = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 500, 572, 100, 8 }, false);
	plank3->Texture(textureManager->GetTexture(PLANK_WOOD_SPRITE));
	entities.push_back(plank3);

	std::shared_ptr<PhysicsEntity> plank4 = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 508, 672, 84, 8 }, false);
	plank4->Texture(textureManager->GetTexture(PLANK_WOOD_SPRITE));
	entities.push_back(plank4);

	/*
	b2Body* link = platform->GetBody();
	b2Body* newLink = nullptr;

	for (int i = 0; i < 5; i++)
	{
		std::shared_ptr<PhysicsEntity> ice_cube = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 16 * i, 16 * i, 7, 80 }, false);
		ice_cube->Texture(textureManager->GetTexture(PLANK_WOOD_SPRITE));

		b2RevoluteJointDef revoluteJointDef;
		if (i == 0) {
			revoluteJointDef.localAnchorA.Set(0, 0);
			revoluteJointDef.localAnchorB.Set(0, 0);
		}
		else {
			revoluteJointDef.localAnchorA.Set(0.40, 0);
			revoluteJointDef.localAnchorB.Set(-0.40, 0);
		}

		newLink = ice_cube->GetBody();
		revoluteJointDef.bodyA = link;
		revoluteJointDef.bodyB = newLink;
		revoluteJointDef.collideConnected = false;

		world->CreateJoint(&revoluteJointDef);

		link->SetLinearDamping(1.0f);
		link = newLink;

		entities.push_back(ice_cube);
	}
	*/
	return Scene::Load();
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
