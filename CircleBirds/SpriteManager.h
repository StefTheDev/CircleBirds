#pragma once

#include "Sprite.h"

enum SpriteType 
{
	PLAYER_RED_SPRITE,
	PLAYER_CHUCK_SPRITE,
	PLATFORM_ICE_SPRITE
};


class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	void Load(SDL_Renderer * renderer);

	static std::shared_ptr<SpriteManager> GetInstance();

	SDL_Texture * Texture(SpriteType spriteType);

private:
	std::vector<std::shared_ptr<Sprite>> sprites;

protected:

	static std::shared_ptr<SpriteManager> spriteManager;
};

