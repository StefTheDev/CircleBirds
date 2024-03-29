#include "GameManager.h"


int main(int argc, char* argv[]) {
	GameManager* gameManager = GameManager::GetInstance();

	if (!gameManager->Initialise()) return 0;

	Uint32 startFrame, timeFrame;

	atexit(SDL_Quit);

	while (gameManager->GetState() != EXIT)
	{
		startFrame = SDL_GetTicks();

		gameManager->HandleEvents();
		gameManager->Update();
		gameManager->Render();

		timeFrame = SDL_GetTicks() - startFrame;
		if (FRAME_DELAY > timeFrame) SDL_Delay(FRAME_DELAY - timeFrame);
	}

	gameManager->Clean();
	return 0;
}