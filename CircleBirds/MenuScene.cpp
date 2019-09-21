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
	background->Texture(spriteManager->Texture(BACKGROUND_SPRITE));
	background->Load(SDL_Rect{ 0, 0, 1600, 800 });
	entities.push_back(background);
	
	
	SDL_Rect rect = SDL_Rect{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0, 0 };

	std::shared_ptr<TextLabel> textLabel = std::make_shared<TextLabel>("Play", [this] {
		std::cout << "Play clicked..." << std::endl;
	});

	textLabel->Texture(spriteManager->Texture(PLAYER_RED_SPRITE));
	textLabel->Load(fontManager->Font(ARIAL_FONT), Vector2{ 150, 50 });
	entities.push_back(textLabel);
	return Scene::Load(); 
}