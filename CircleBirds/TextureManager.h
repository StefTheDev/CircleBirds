#pragma once
#include "Sprite.h"

enum FontTexture {
	ARIAL_FONT = 0,
	ANGRY_FONT
};

enum SpriteTexture
{
	PLAYER_RED_SPRITE = 0,
	PLAYER_CHUCK_SPRITE,
	PLAYER_BLUEY_SPRITE,
	PLATFORM_ICE_SPRITE,
	PLATFORM_WOOD_SPRITE,
	PLATFORM_STONE_SPRITE,
	PLANK_WOOD_SPRITE,
	CATAPULT_SPRITE,
	BACKGROUND_SPRITE,
	GROUND_SPRITE,
	LOGO_SPRITE,
	PLAY_TEXT_SPRITE,
	QUIT_TEXT_SPRITE,
};

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static std::shared_ptr<TextureManager> GetInstance();

	void Load(SDL_Renderer* renderer);

	SDL_Texture* GetTexture(SpriteTexture spriteTexture);

private:
	std::vector<std::shared_ptr<Sprite>> sprites;
	std::vector<TTF_Font*> fonts;

	static std::shared_ptr<TextureManager> textureManager;
};

