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
	SpriteManager();
	~SpriteManager();

	void Load(SDL_Renderer * renderer);

	std::shared_ptr<Sprite> GetSprite(SpriteType spriteType);

	static std::shared_ptr<SpriteManager> GetInstance();

private:
	std::vector<std::shared_ptr<Sprite>> sprites;

protected:

	static std::shared_ptr<SpriteManager> spriteManager;
};

