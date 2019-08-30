#include "GameManager.h"

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
	SpriteManager::GetInstance()->Load(renderer);

	if (surface == nullptr) return false;


	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!IMG_Init(imageFlags) & imageFlags) return false;

	scenes.push_back(std::make_unique<MenuScene>());
	scenes.push_back(std::make_unique<GameScene>());

	return Switch(INGAME);
}

void GameManager::Render()
{
	SDL_RenderClear(renderer);

	if(gameState != EXIT) scenes[gameState]->Render(renderer);

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
	timeLastFrame = timeCurrentFrame;
	timeCurrentFrame = SDL_GetPerformanceCounter();

	DELTA_TIME = (float)((timeCurrentFrame - timeLastFrame) / (float)SDL_GetPerformanceFrequency());
	if (gameState != EXIT) scenes[gameState]->Update();

	SDL_GetMouseState(&mouseX, &mouseY);

	std::string string = "Circle Birds | " + scenes[gameState]->ToString() + " | Mouse Position: x:" + std::to_string(mouseX) + ", y:" + std::to_string(mouseY);
	SDL_SetWindowTitle(window, string.c_str());
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

bool GameManager::Switch(GameState gameState)
{
	if (scenes[this->gameState]->Unload()) this->gameState = gameState;
	return scenes[this->gameState]->Load();
}
