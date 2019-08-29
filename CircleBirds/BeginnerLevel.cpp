#include "BeginnerLevel.h"

BeginnerLevel::BeginnerLevel()
{
}


BeginnerLevel::~BeginnerLevel()
{
}

bool BeginnerLevel::Initialise(b2Vec2 gravity)
{
	SpriteManager& spriteManager = SpriteManager::GetInstance();

	std::vector<std::shared_ptr<Entity>> entities;

	std::shared_ptr<Entity> player = std::make_shared<Player>();
	if (player->Initialise(Vector2{ 0, 0 })) {
		player->SetSprite(spriteManager.GetSprite(PLAYER_SPRITE));
	}
	else 
	{
		return false;
	}

	return Level::Initialise(gravity, entities);
}
