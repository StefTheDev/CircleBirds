#include "GameScene2.h"



GameScene2::GameScene2() : Scene("Game Scene 2")
{
	
}


GameScene2::~GameScene2()
{
}

bool GameScene2::Load()
{
	world = new b2World(b2Vec2{ 0.0f, 3.2f });

	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 }, textureManager->GetTexture(BACKGROUND_SPRITE)));

	std::shared_ptr<PhysicsEntity> ground = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 0, 680, 1280, 120 }, true, textureManager->GetTexture(GROUND_SPRITE));
	entities.push_back(ground);

	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 550, 32, 80 }, textureManager->GetTexture(CATAPULT_SPRITE)));
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 120, 630, 48, 48 }, textureManager->GetTexture(WOOD_PLANK_SPRITE)));

	entities.push_back(std::make_shared<PlayerHandler>(SDL_Rect{ 64, 536, 32, 32 }, world, std::shared_ptr<Scene>(this), textureManager->GetTexture(PLAYER_RED_SPRITE)));

	int windmillLength = 300;
	int windmillWidth = 16;

	std::shared_ptr<PhysicsEntity> spinnyBoi = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 800 - windmillLength/2, 400 - windmillWidth/2, windmillLength, windmillWidth }, false, textureManager->GetTexture(WOOD_PLANK_SPRITE));
	entities.push_back(spinnyBoi);
	std::shared_ptr<PhysicsEntity> spinnyBoi2 = std::make_shared<PhysicsEntity>(*world, BOX_ENTITY, SDL_Rect{ 800 - windmillWidth / 2, 400 - windmillLength / 2, windmillWidth, windmillLength }, false, textureManager->GetTexture(WOOD_PLANK_SPRITE));
	entities.push_back(spinnyBoi2);

	b2WeldJointDef joinyJoint;
	joinyJoint.bodyA = spinnyBoi2->GetBody();
	joinyJoint.bodyB = spinnyBoi->GetBody();
	joinyJoint.localAnchorA.Set(0.5, 0.5);
	joinyJoint.localAnchorB.Set(0.5, 0.5);
	joinyJoint.collideConnected = false;
	b2RevoluteJointDef jointdef;
	jointdef.bodyA = ground->GetBody();
	jointdef.bodyB = spinnyBoi->GetBody();
	jointdef.localAnchorA.Set(0.5, -3);
	jointdef.localAnchorB.SetZero();
	jointdef.enableMotor = true;
	jointdef.maxMotorTorque = 20;
	jointdef.motorSpeed = 60 * 0.01745329252;

	world->CreateJoint(&joinyJoint);
	world->CreateJoint(&jointdef);



	return Scene::Load();
}

void GameScene2::Update()
{
	world->Step(DELTA_TIME, 3, 8);
	Scene::Update();
}
