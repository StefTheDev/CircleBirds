#include "Player.h"

Player::Player()
{

}


Player::~Player()
{

}

bool Player::Initialise(Vector2 position)
{
	//Collider stuff

	return Entity::Initialise(position);
}

void Player::Update()
{
	Transform(Vector2{ 2.0f, 3.0f });
	Rotate(2.0f);

	return Entity::Update();
}

void Player::Render()
{
	return Entity::Render();
}

void Player::Listen(SDL_Event event)
{
	int mouseX, mouseY;
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {

			Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
			std::string string = std::to_string(mouseX) + " " + std::to_string(mouseY);

			if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				std::cout << "Mouse Clicked: " << string.c_str() << std::endl;
			}
			else {
				std::cout << "Mouse Movement: " << string.c_str() << std::endl;
			}

		} break;
		case SDL_KEYDOWN: {
			switch (event.key.keysym.sym) {
				case SDLK_LEFT: {
					std::cout << "Left" << std::endl;
				} break;
				case SDLK_RIGHT: {
					std::cout << "Right" << std::endl;
				} break;
				case SDLK_UP: {
					std::cout << "Up" << std::endl;
				} break;
				case SDLK_DOWN: {
					std::cout << "Down" << std::endl;
				} break;
			}
			//Keyboard input
		}
	}
	return Entity::Listen(event);
}