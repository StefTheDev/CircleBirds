#pragma once

#include "Utilities.h"

class Scene;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

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
	GameManager(std::string title);
	~GameManager();

	bool Initialise();

	void Render();
	void HandleEvents();
	void Update();
	void Clean();

	SDL_Window * GetWindow();
	SDL_Renderer* GetRenderer();
	SDL_Surface* GetSurface();

	GameState GetState() const;

	bool Switch(GameState gameState);

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Surface * surface;

	GameState gameState;

	int mouseX, mouseY;
	Uint64 timeCurrentFrame, timeLastFrame;

	std::vector<std::unique_ptr<Scene>> scenes;
};