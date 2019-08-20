#include "Player.h"

Player::Player()
{

}


Player::~Player()
{

}

bool Player::Initialise(SDL_Renderer * renderer)
{
	//Initialise Game Controller.
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			gameController = SDL_GameControllerOpen(i);
			break;
		}
	}

	return Entity::Initialise(std::make_shared<Sprite>("Player.png", renderer));
}

void Player::Update()
{
	//Controller input...

	return Entity::Update();
}

void Player::Render()
{
	return Entity::Render();
}
