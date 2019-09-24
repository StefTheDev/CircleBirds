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

	std::shared_ptr<Entity> catapult = std::make_shared<Entity>(SDL_Rect{ 160, 420, 64, 159 });
	catapult->Texture(textureManager->GetTexture(CATAPULT_SPRITE));
	

	std::shared_ptr<PhysicsEntity> platform = std::make_shared<PhysicsEntity>(*world, CIRCLE_ENTITY, SDL_Rect{ 500, 400, 32, 32 }, true);
	platform->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));

	std::shared_ptr<PlayerHandler> playerHandler = std::make_shared<PlayerHandler>(SDL_Rect{64, 536, 64, 64}, world, std::shared_ptr<Scene>(this));
	playerHandler->Texture(textureManager->GetTexture(PLAYER_RED_SPRITE));

	std::shared_ptr<PhysicsEntity> ground = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 0, 600, 1600, 200 }, true);
	ground->Texture(textureManager->GetTexture(PLATFORM_ICE_SPRITE));

	entities.push_back(background);
	entities.push_back(catapult);
	entities.push_back(ground);

	b2Body* link = platform->GetBody();
	b2Body* newLink = nullptr;

	for (int i = 0; i < 5; i++) {
		std::shared_ptr<PhysicsEntity> ice_cube = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 16 * i, 16 * i, 32, 32 }, false);
		ice_cube->Texture(textureManager->GetTexture(PLATFORM_WOOD_SPRITE));
		newLink = ice_cube->GetBody();

		b2RevoluteJointDef revoluteJointDef;
		if (i == 0) {
			revoluteJointDef.localAnchorA.Set(0, 0);
			revoluteJointDef.localAnchorB.Set(0, 0);
		}
		else {
			revoluteJointDef.localAnchorA.Set(0.15, 0);
			revoluteJointDef.localAnchorB.Set(-0.15, 0);
		}

		link->SetLinearDamping(1.0f);
		revoluteJointDef.bodyA = link;
		revoluteJointDef.bodyB = newLink;
		world->CreateJoint(&revoluteJointDef);

		link = newLink;

		entities.push_back(ice_cube);
	}

	entities.push_back(platform);
	entities.push_back(playerHandler);

	return Scene::Load();
}

void GameScene::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
