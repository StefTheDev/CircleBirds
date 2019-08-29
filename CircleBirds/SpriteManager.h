#pragma once

#include "Sprite.h"

enum SpriteType 
{
	PLAYER_SPRITE,
	PLATFORM_SPRITE,
};


class SpriteManager
{
public:
	~SpriteManager();

	void Load(SDL_Renderer * renderer);

	std::shared_ptr<Sprite> GetSprite(SpriteType spriteType);

	static SpriteManager & GetInstance();
	static void DestroyInstance();

private:
	SpriteManager();
	std::vector<std::shared_ptr<Sprite>> sprites;

protected:

	static SpriteManager* spriteManager;
};

