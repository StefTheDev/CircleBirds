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

		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF));
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

	std::unique_ptr<MenuScene> menuScene = std::make_unique<MenuScene>();

	if (!menuScene->Initialise()) return false;
	scenes.push_back(std::move(menuScene));

	std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();

	if (!gameScene->Initialise()) return false;
	scenes.push_back(std::move(gameScene));
	
	gameState = MENU;

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
	switch (event.type)
	{
		case SDL_QUIT: {

		} break;
		default:
			break;
	}
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
