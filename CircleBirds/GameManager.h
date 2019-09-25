#pragma once

#include "Utilities.h"

class Scene;

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

enum GameState {
	MENU,
	INGAME,
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

private:
	SDL_Window * window;
	SDL_Renderer * renderer;

	GameState gameState;

	int mouseX, mouseY;
	Uint64 timeCurrentFrame, timeLastFrame;

	std::vector<std::unique_ptr<Scene>> scenes; 


	GameManager(std::string string);
	static GameManager* instance;

};