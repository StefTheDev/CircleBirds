#include "TextureManager.h"

std::shared_ptr<TextureManager> TextureManager::textureManager = nullptr;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	for (auto& font : fonts) {
		TTF_CloseFont(font);
	}
}

std::shared_ptr<TextureManager> TextureManager::GetInstance()
{
	if (textureManager == nullptr) textureManager = std::make_shared<TextureManager>();
	return textureManager;
}

void TextureManager::Load(SDL_Renderer* renderer)
{
	//FONTS
	fonts.push_back(TTF_OpenFont("Resources/Fonts/ARIAL_BOLD.TTF", 64));

	//TEXTURES
	std::shared_ptr<Sprite> sprite = nullptr;

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Birds/Red.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Birds/Chuck.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Birds/Bluey.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Platforms/Ice.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Platforms/Wood.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Platforms/Stone.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Catapult.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Background.png");
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadText("Play", fonts[ARIAL_FONT], SDL_Color{ 255, 255, 255 });
	sprites.push_back(sprite);

	sprite = std::make_unique <Sprite>(renderer);
	sprite->LoadText("Quit", fonts[ARIAL_FONT], SDL_Color{ 255, 255, 255 });
	sprites.push_back(sprite);
}

SDL_Texture* TextureManager::GetTexture(SpriteTexture spriteTexture)
{
	if (spriteTexture < 0 || spriteTexture >= sprites.size()) return nullptr;
	return sprites[spriteTexture]->GetTexture();
}
