#include "SpriteManager.h"


SpriteManager* SpriteManager::spriteManager = nullptr;


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{

}

void SpriteManager::Load(SDL_Renderer * renderer)
{
	sprites.push_back(std::make_shared<Sprite>("Resources/Sprites/Player.png", renderer));
	sprites.push_back(std::make_shared<Sprite>("Resources/Sprites/Platform.png", renderer));
}

SpriteManager & SpriteManager::GetInstance()
{
	if (spriteManager == nullptr) spriteManager = new SpriteManager();
	return *spriteManager;
}

void SpriteManager::DestroyInstance()
{
	delete spriteManager;
	spriteManager = nullptr;
}

std::shared_ptr<Sprite> SpriteManager::GetSprite(SpriteType spriteType)
{
	return sprites[spriteType];
}
