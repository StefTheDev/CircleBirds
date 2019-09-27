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
	ENEMY_PIG_SPRITE,
	STONE_BRICK_SPRITE,
	WOOD_PLANK_SPRITE,
	CATAPULT_SPRITE,
	BACKGROUND_SPRITE,
	GROUND_SPRITE,
	LOGO_SPRITE,
	LEVEL1_TEXT_SPRITE,
	LEVEL2_TEXT_SPRITE,
};

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	static TextureManager* GetInstance();

	void Load(SDL_Renderer* renderer);

	SDL_Texture* GetTexture(SpriteTexture spriteTexture);

private:
	std::vector<std::shared_ptr<Sprite>> sprites;
	std::vector<TTF_Font*> fonts;

	static TextureManager* textureManager;
};

