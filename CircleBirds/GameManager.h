#pragma once

#include "Utilities.h"

class Scene;

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

enum GameState {
	MENU,
	LEVEL1,
	LEVEL2,
	EXIT
};

class GameManager
{
public:
	
	static GameManager* GetInstance();

	~GameManager();

	bool Initialise();

	void Render();
	void HandleEvents();
	void Update();
	void Clean();

	SDL_Window * GetWindow();
	SDL_Renderer* GetRenderer();

	GameState GetState() const;

	bool Switch(GameState gameState);
	bool switchFlag = false;
	GameState gameState;
private:
	SDL_Window * window;
	SDL_Renderer * renderer;


	int mouseX, mouseY;
	Uint64 timeCurrentFrame, timeLastFrame;

	std::shared_ptr<Scene> scene; 


	GameManager(std::string string);
	static GameManager* instance;
	
};