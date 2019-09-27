#include "GameManager.h"

//Scenes
#include "MenuScene.h"
#include "GameScene.h"
#include "GameScene2.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(std::string string)
{
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	
		SDL_DisplayMode displayMode;
		SDL_GetCurrentDisplayMode(0, &displayMode);

		window = SDL_CreateWindow(string.c_str(), (displayMode.w - WINDOW_WIDTH) / 2,(displayMode.h - WINDOW_HEIGHT) / 2, WINDOW_WIDTH, WINDOW_HEIGHT, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
	}
}

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr) instance = new GameManager("CircleBirds");
	return instance;
}

GameManager::~GameManager()
{

}

bool GameManager::Initialise()
{

	if (window == nullptr) return false;
	if (renderer == nullptr) return false;

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!IMG_Init(imageFlags) & imageFlags) return false;


	if (TTF_Init() == -1) return false;

	scenes.push_back(std::make_shared<MenuScene>());
	scenes.push_back(std::make_shared<GameScene2>());

	TextureManager::GetInstance()->Load(renderer);

	return Switch(MENU);
}

void GameManager::Render()
{
	if (gameState != EXIT) {
		SDL_RenderClear(renderer);

		scenes[gameState]->Render(renderer);

		SDL_RenderPresent(renderer);
	}
}

void GameManager::HandleEvents()
{
	if (gameState != EXIT) {
		SDL_Event event;
		SDL_PollEvent(&event);
		scenes[gameState]->Listen(event);
	}
}

void GameManager::Update()
{
	if (gameState != EXIT) {
		timeLastFrame = timeCurrentFrame;
		timeCurrentFrame = SDL_GetPerformanceCounter();

		DELTA_TIME = (float)((timeCurrentFrame - timeLastFrame) / (float)SDL_GetPerformanceFrequency());
		if (DELTA_TIME > 0.3f) DELTA_TIME = 0.3f;
		scenes[gameState]->Update();

		SDL_GetMouseState(&mouseX, &mouseY);

		std::string string = "Circle Birds | " + scenes[gameState]->ToString() + " | Mouse Position: x:" + std::to_string(mouseX) + ", y:" + std::to_string(mouseY);
		SDL_SetWindowTitle(window, string.c_str());
	}
}

void GameManager::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit(0);
}

SDL_Window * GameManager::GetWindow()
{
	return window;
}

SDL_Renderer* GameManager::GetRenderer()
{
	return renderer;
}

GameState GameManager::GetState() const
{
	return gameState;
}

bool GameManager::Switch(GameState _gameState)
{
	 gameState = _gameState;
	return scenes[gameState]->Load();
}