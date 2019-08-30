#include "SpriteManager.h"


std::shared_ptr<SpriteManager> SpriteManager::spriteManager = nullptr;


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{

}

void SpriteManager::Load(SDL_Renderer * renderer)
{
	sprites.push_back(std::make_shared<Sprite>("Resources/Sprites/Birds/Red.png", renderer));
	sprites.push_back(std::make_shared<Sprite>("Resources/Sprites/Birds/Chuck.png", renderer));
	sprites.push_back(std::make_shared<Sprite>("Resources/Sprites/Platforms/Ice.png", renderer));
}

std::shared_ptr<SpriteManager> SpriteManager::GetInstance()
{
	if (spriteManager == nullptr) spriteManager = std::make_shared<SpriteManager>();
	return spriteManager;
}

std::shared_ptr<Sprite> SpriteManager::GetSprite(SpriteType spriteType)
{
	if (spriteType < 0 || spriteType >= sprites.size()) return nullptr;
	return sprites[spriteType];
}
