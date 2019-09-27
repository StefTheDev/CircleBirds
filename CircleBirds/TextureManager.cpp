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
	fonts.push_back(TTF_OpenFont("Resources/Fonts/FEASFBI_.TTF", 80));

	//TEXTURES
	std::shared_ptr<Sprite> sprite = nullptr;

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Characters/Red.png");
	sprites.push_back(sprite);
	
	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Characters/Chuck.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Characters/Bluey.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Characters/Pig.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Materials/Stone-Brick.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/Materials/Wood-Plank.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Catapult.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Background.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Ground.png");
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadImageFromFile("Resources/Sprites/General/Logo.png");
	sprites.push_back(sprite);


	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadText("Play", fonts[ANGRY_FONT], SDL_Color{ 255, 255, 255 });
	sprites.push_back(sprite);

	sprite = std::make_shared <Sprite>(renderer);
	sprite->LoadText("Quit", fonts[ANGRY_FONT], SDL_Color{ 255, 255, 255 });
	sprites.push_back(sprite);
}

SDL_Texture* TextureManager::GetTexture(SpriteTexture spriteTexture)
{
	if (spriteTexture < 0 || spriteTexture >= sprites.size()) return nullptr;
	return sprites[spriteTexture]->GetTexture();
}
