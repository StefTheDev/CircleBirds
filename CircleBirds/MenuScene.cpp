#include "MenuScene.h"

MenuScene::MenuScene() : Scene("Menu Scene")
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Load()
{
	std::shared_ptr<Entity> background = std::make_shared<Entity>();
	background->Texture(textureManager->GetTexture(BACKGROUND_SPRITE));
	if(!background->Load(SDL_Rect{ 0, 0, 1600, 800 })) return false;
	entities.push_back(background);
	
	
	int width, height = 0;
	SDL_QueryTexture(textureManager->GetTexture(PLAY_TEXT_SPRITE), NULL, NULL, &width, &height);
	SDL_Rect rect = SDL_Rect{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50, width, height };

	std::shared_ptr<TextLabel> play = std::make_shared<TextLabel>([this] {
		std::cout << "Play clicked..." << std::endl;
	});

	play->Texture(textureManager->GetTexture(PLAY_TEXT_SPRITE));
	if (!play->Load(rect)) return false;
	entities.push_back(play);

	SDL_QueryTexture(textureManager->GetTexture(QUIT_TEXT_SPRITE), NULL, NULL, &width, &height);
	rect = SDL_Rect{ WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2) + 40, width, height };

	std::shared_ptr<TextLabel> Quit = std::make_shared<TextLabel>([this] {
		std::cout << "Quit clicked..." << std::endl;
		});

	Quit->Texture(textureManager->GetTexture(QUIT_TEXT_SPRITE));
	if (!Quit->Load(rect)) return false;
	entities.push_back(Quit);

	return Scene::Load(); 
}