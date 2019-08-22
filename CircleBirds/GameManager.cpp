#include "GameManager.h"
#include "Scene.h"

//Scenes
#include "MenuScene.h"
#include "GameScene.h"

GameManager::GameManager(std::string title)
{
	Uint32 flags = SDL_WINDOW_SHOWN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		SDL_DisplayMode displayMode;
		SDL_GetCurrentDisplayMode(0, &displayMode);

		auto width = displayMode.w, height = displayMode.h;
		auto xPosition = (width - WINDOW_WIDTH) / 2, yPosition = (height - WINDOW_HEIGHT) / 2;

		window = SDL_CreateWindow(title.c_str(), xPosition, yPosition, WINDOW_WIDTH, WINDOW_HEIGHT, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		surface = SDL_GetWindowSurface(window);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_UpdateWindowSurface(window);
	}
}

GameManager::~GameManager()
{

}

bool GameManager::Initialise()
{
	if (window == nullptr) return false;
	if (renderer == nullptr) return false;
	if (surface == nullptr) return false;


	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!IMG_Init(imageFlags) & imageFlags) return false;

	std::unique_ptr<MenuScene> menuScene = std::make_unique<MenuScene>();

	if (!menuScene->Initialise(renderer)) return false;
	scenes.push_back(std::move(menuScene));

	std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();

	if (!gameScene->Initialise(renderer)) return false;
	scenes.push_back(std::move(gameScene));
	
	gameState = INGAME;

	return true;
}

void GameManager::Render()
{
	SDL_RenderClear(renderer);

	if(gameState != EXIT) scenes[gameState]->Render();

	SDL_RenderPresent(renderer);
}

void GameManager::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (gameState != EXIT) scenes[gameState]->Event(event);
}

void GameManager::Update()
{
	if (gameState != EXIT) scenes[gameState]->Update();
}

void GameManager::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

SDL_Window * GameManager::GetWindow()
{
	return window;
}

SDL_Renderer* GameManager::GetRenderer()
{
	return renderer;
}

SDL_Surface * GameManager::GetSurface()
{
	return surface;
}

GameState GameManager::GetState() const
{
	return gameState;
}
