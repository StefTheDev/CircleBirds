#include "Player.h"

Player::Player(SDL_Rect rect) : Entity(rect)
{
}

Player::~Player()
{

}

void Player::Update()
{
	position += 1.0f;
	Entity::Update();
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
				//std::cout << "Mouse Clicked: " << string.c_str() << std::endl;
			}
			else {
				//std::cout << "Mouse Movement: " << string.c_str() << std::endl;
			}

		} break;
		case SDL_KEYDOWN: {
			switch (event.key.keysym.sym) {
				case SDLK_LEFT: {
					//std::cout << "Left" << std::endl;
				} break;
				case SDLK_RIGHT: {
					//std::cout << "Right" << std::endl;
				} break;
				case SDLK_UP: {
					//std::cout << "Up" << std::endl;
				} break;
				case SDLK_DOWN: {
					//std::cout << "Down" << std::endl;
				} break;
			}
			//Keyboard input
		}
	}
	return Entity::Listen(event);
}