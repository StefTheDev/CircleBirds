#include "GameScene.h"

GameScene::GameScene() : Scene("Game Scene")
{
	world = new b2World(b2Vec2{ 0.0f, 3.2f });
}

GameScene::~GameScene()	
{

}

bool GameScene::Load()
{
	
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 }, textureManager->GetTexture(BACKGROUND_SPRITE)));
	
	std::shared_ptr<PhysicsEntity> ground = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 0, 680, 1280, 120 }, true, textureManager->GetTexture(GROUND_SPRITE));
	entities.push_back(ground);

	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 550, 32, 80 }, textureManager->GetTexture(CATAPULT_SPRITE)));
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 630, 48, 48 }, textureManager->GetTexture(PLATFORM_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PlayerHandler>(SDL_Rect{ 64, 536, 32, 32 }, world, std::shared_ptr<Scene>(this), textureManager->GetTexture(PLAYER_RED_SPRITE)));

	//First Box
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 500, 580, 8, 100 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 592, 580, 8, 100 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 500, 572, 100, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 508, 672, 84, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));

	//Second Box
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 510, 500, 8, 80 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 580, 500, 8, 80 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 508, 490, 80, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 518, 572, 64, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));


	//Second Box
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 700, 580, 8, 100 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 792, 580, 8, 100 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 700, 572, 100, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 708, 672, 84, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));

	//Second Box
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 710, 500, 8, 80 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 780, 500, 8, 80 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 708, 490, 80, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));
	entities.push_back(std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 718, 572, 64, 8 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE)));


	b2Body* link = ground->GetBody();
	b2Body * newLink = nullptr;

	for (int i = 0; i < 12; i++)
	{
		std::shared_ptr<PhysicsEntity> cube = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 600, 550, 20, 7 }, false, textureManager->GetTexture(PLANK_WOOD_SPRITE));
	
		b2RevoluteJointDef revoluteJointDef;
		if (i == 0) {
			revoluteJointDef.localAnchorA.Set(0, -4.0);
			revoluteJointDef.localAnchorB.Set(-0.2, 0);
		}
		else {
			revoluteJointDef.localAnchorA.Set(0.095, 0);
			revoluteJointDef.localAnchorB.Set(-0.095, 0);
		}

		newLink = cube->GetBody();
		revoluteJointDef.bodyA = link;
		revoluteJointDef.bodyB = newLink;
		revoluteJointDef.collideConnected = false;

		world->CreateJoint(&revoluteJointDef);

		link->SetLinearDamping(5.0f);
		link = newLink;

		entities.push_back(cube);

	}
	return Scene::Load();
}

void GameScene::Update()
{

	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
