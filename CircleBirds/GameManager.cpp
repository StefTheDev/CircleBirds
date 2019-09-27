#include "GameManager.h"

//Scenes
#include "MenuScene.h"
#include "GameScene.h"

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
	delete instance;
}

bool GameManager::Initialise()
{

	if (window == nullptr) return false;
	if (renderer == nullptr) return false;

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!IMG_Init(imageFlags) & imageFlags) return false;

	if (TTF_Init() == -1) return false;

	return Switch(MENU);
}

void GameManager::Render()
{
	SDL_RenderClear(renderer);

	if (gameState != EXIT) scene->Render(renderer);

	SDL_RenderPresent(renderer);
}

void GameManager::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (gameState != EXIT)scene->Listen(event);
}

void GameManager::Update()
{
	timeLastFrame = timeCurrentFrame;
	timeCurrentFrame = SDL_GetPerformanceCounter();

	DELTA_TIME = (float)((timeCurrentFrame - timeLastFrame) / (float)SDL_GetPerformanceFrequency());
	if (DELTA_TIME > 0.3f) DELTA_TIME = 0.3f;
	if (gameState != EXIT) scene->Update();

	SDL_GetMouseState(&mouseX, &mouseY);

	std::string string = "Circle Birds | " + scene->ToString() + " | Mouse Position: x:" + std::to_string(mouseX) + ", y:" + std::to_string(mouseY);
	SDL_SetWindowTitle(window, string.c_str());

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

std::shared_ptr<Scene> GameManager::GetScene()
{
	return scene;
}



GameState GameManager::GetState() const
{
	return gameState;
}

bool GameManager::Switch(GameState _gameState)
{
	gameState = _gameState;

	switch (gameState)
	{
		case MENU: {
			scene = std::make_shared<MenuScene>();
		} break;
		case LEVEL1: {
			scene = std::make_shared<GameScene>();
		} break;
		case LEVEL2: {
			scene = std::make_shared<GameScene>();
		} break;
	}

	TextureManager::GetInstance()->Load(renderer);
	
	return scene->Load();
}