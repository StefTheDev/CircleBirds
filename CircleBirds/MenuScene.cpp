#include "MenuScene.h"

#include "GameManager.h"
#include "TextureManager.h"

MenuScene::MenuScene() : Scene("Menu")
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Load()
{
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 }, TextureManager::GetInstance()->GetTexture(BACKGROUND_SPRITE)));
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 100, 100, 500, 90 }, TextureManager::GetInstance()->GetTexture(LOGO_SPRITE)));
	
	int width, height = 0;
	
	SDL_QueryTexture(TextureManager::GetInstance()->GetTexture(LEVEL1_TEXT_SPRITE), NULL, NULL, &width, &height);
	SDL_Rect rect = SDL_Rect{ 100, 220, width, height };
	entities.push_back(std::make_shared<TextLabel>([this] {
		GameManager::GetInstance()->Switch(LEVEL1);
	}, rect, TextureManager::GetInstance()->GetTexture(LEVEL1_TEXT_SPRITE)));

	SDL_QueryTexture(TextureManager::GetInstance()->GetTexture(LEVEL2_TEXT_SPRITE), NULL, NULL, &width, &height);
	rect = SDL_Rect{ 100, 300, width, height };
	entities.push_back(std::make_shared<TextLabel>([this] {
		GameManager::GetInstance()->Switch(LEVEL2);
	}, rect, TextureManager::GetInstance()->GetTexture(LEVEL2_TEXT_SPRITE)));

	return Scene::Load(); 
}