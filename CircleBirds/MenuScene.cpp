#include "MenuScene.h"
#include "GameManager.h"

MenuScene::MenuScene() : Scene("Menu Scene")
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Load()
{
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 0, 0, 1280, 800 }, textureManager->GetTexture(BACKGROUND_SPRITE)));
	entities.push_back(std::make_shared<Entity>(SDL_Rect{ 100, 100, 500, 90 }, textureManager->GetTexture(LOGO_SPRITE)));
	
	int width, height = 0;
	
	SDL_QueryTexture(textureManager->GetTexture(PLAY_TEXT_SPRITE), NULL, NULL, &width, &height);
	SDL_Rect rect = SDL_Rect{ 100, 220, width, height };
	entities.push_back(std::make_shared<TextLabel>([this] {
		GameManager::GetInstance()->Switch(INGAME);
	}, rect, textureManager->GetTexture(PLAY_TEXT_SPRITE)));

	SDL_QueryTexture(textureManager->GetTexture(QUIT_TEXT_SPRITE), NULL, NULL, &width, &height);
	rect = SDL_Rect{ 100, 300, width, height };
	entities.push_back(std::make_shared<TextLabel>([this] {
		std::cout << "Quit clicked..." << std::endl;
		}, rect, textureManager->GetTexture(QUIT_TEXT_SPRITE)));

	return Scene::Load(); 
}