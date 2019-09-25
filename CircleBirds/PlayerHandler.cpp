#include "PlayerHandler.h"

PlayerHandler::PlayerHandler(SDL_Rect _rect, b2World* _world, std::shared_ptr<Scene> _scene) : Entity(_rect), world(_world), scene(_scene)
{
	destination.x = catapultLocation.x - _rect.w * 0.5f;
	destination.y = catapultLocation.y - _rect.h * 0.5f;
}

void PlayerHandler::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x5d, 0x40, 0x1a, 0xff);

	SDL_RenderDrawLine(renderer, catapultLocation.x - 30, catapultLocation.y, destination.x + source.w * 0.5, destination.y + source.h * 0.5);
	SDL_RenderDrawLine(renderer, catapultLocation.x + 30, catapultLocation.y, destination.x + source.w * 0.5, destination.y + source.h * 0.5);

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);

	Entity::Render(renderer);
}

void PlayerHandler::Listen(SDL_Event event)
{
	if (amount <= 0) return;

	int mouseX, mouseY;
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN: {
		Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
		if (((mouseX > destination.x) && (mouseX < destination.x + destination.w) && (mouseY > destination.y) && (mouseY < destination.y + destination.h))) active = true;
	} break;
	case SDL_MOUSEMOTION: {

		Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
		std::string string = std::to_string(mouseX) + " " + std::to_string(mouseY);

		if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) && active) {
			destination.y = max(0, min(mouseY - source.h * 0.5f, 600.0f - source.h));
			destination.x = max(0, min(mouseX - source.w * 0.5f, 1600.0f - source.w));
			float distToCatapult = b2Distance(catapultLocation, b2Vec2(mouseX, mouseY));
			if (distToCatapult > maxDistToCatapult) {
				destination.y = max(0, min(catapultLocation.y + (mouseY - catapultLocation.y) * maxDistToCatapult / distToCatapult - source.h * 0.5f, 600.0f - source.h));
				destination.x = max(0, min(catapultLocation.x + (mouseX - catapultLocation.x) * maxDistToCatapult / distToCatapult - source.w * 0.5f, 1600.0f - source.w));
			}
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
	} break;
	case SDL_MOUSEBUTTONUP: {
		if (event.button.button == 1 && active) {
			std::shared_ptr<Player> newPlayer = std::make_shared<Player>(*world, destination, 1.0f * PIXEL_TO_METER * (catapultLocation - (b2Vec2{ static_cast<float>(destination.x), static_cast<float>(destination.y) } + b2Vec2{ source.w * 0.5f, source.h * 0.5f })) );
			newPlayer->Texture(scene->GetTextureManager()->GetTexture(PLAYER_RED_SPRITE));
			scene->AddEntity(newPlayer);
			destination.x = catapultLocation.x - source.w * 0.5f;
			destination.y = catapultLocation.y - source.h * 0.5f;
			active = false;
			amount --;
		}
	}break;
	}
	return Entity::Listen(event);
}