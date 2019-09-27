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
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 630, 48, 48 }, textureManager->GetTexture(WOOD_PLANK_SPRITE)));

	GenerateTower(-100, 0);
	GenerateTower(300, 0);

	entities.push_back(std::make_shared<Pig>(*world, SDL_Rect{ 435, 500, 32, 32 }));
	entities.push_back(std::make_shared<Pig>(*world, SDL_Rect{ 835, 500, 32, 32 }));

	entities.push_back(std::make_shared<PlayerHandler>(SDL_Rect{ 64, 536, 32, 32 }, world, std::shared_ptr<Scene>(this), textureManager->GetTexture(PLAYER_RED_SPRITE)));


	b2Body* link = ground->GetBody();
	b2Body * newLink = nullptr;

	for (int i = 0; i < 8; i++)
	{
		std::shared_ptr<PhysicsEntity> entity;
		if (i == 7) {
			entity = std::make_shared<Pig>(*world, SDL_Rect{ 435, 500, 32, 32 });
		}
		else {
			entity = std::make_shared<WoodPlank>(*world, SDL_Rect{ 650, 600, 20, 7 });
		}
	
		b2RevoluteJointDef revoluteJointDef;
		if (i == 0) {
			revoluteJointDef.localAnchorA.Set(0, -3.0);
			revoluteJointDef.localAnchorB.Set(-0.2, 0);
		}
		else if (i == 7) {
			revoluteJointDef.localAnchorA.Set(0, 0);
			revoluteJointDef.localAnchorB.Set(0, 0);
		}
		else {
			revoluteJointDef.localAnchorA.Set(0.095, 0);
			revoluteJointDef.localAnchorB.Set(-0.095, 0);
		}

		newLink = entity->GetBody();
		revoluteJointDef.bodyA = link;
		revoluteJointDef.bodyB = newLink;
		revoluteJointDef.collideConnected = false;

		world->CreateJoint(&revoluteJointDef);

		link->SetLinearDamping(3.0f);
		link = newLink;

		entities.push_back(entity);
	}


	return Scene::Load();
}

void GameScene::Update()
{

	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}

void GameScene::GenerateTower(int xOffset, int yOffset) {
	entities.push_back(std::make_shared<StoneBrick>(*world, SDL_Rect{ 484 + xOffset, 660 + yOffset, 32, 32 }));
	entities.push_back(std::make_shared<StoneBrick>(*world, SDL_Rect{ 516 + xOffset, 660 + yOffset, 32, 32 }));
	entities.push_back(std::make_shared<StoneBrick>(*world, SDL_Rect{ 548 + xOffset, 660 + yOffset, 32, 32 }));
	entities.push_back(std::make_shared<StoneBrick>(*world, SDL_Rect{ 580 + xOffset, 660 + yOffset, 32, 32 }));


	//Second Box
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 500 + xOffset, 548 + yOffset, 8, 100 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 592 + xOffset, 548 + yOffset, 8, 100 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 500 + xOffset, 540 + yOffset, 100, 8 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 508 + xOffset, 640 + yOffset, 84, 8 }));

	//Second Box
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 510 + xOffset, 468 + yOffset, 8, 80 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 580 + xOffset, 468 + yOffset, 8, 80 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 508 + xOffset, 458 + yOffset, 80, 8 }));
	entities.push_back(std::make_shared<WoodPlank>(*world, SDL_Rect{ 518 + xOffset, 540 + yOffset, 64, 8 }));
}
