#include "PlayerHandler.h"

PlayerHandler::PlayerHandler(SDL_Rect _rect, b2World* _world, std::shared_ptr<Scene> _scene, SDL_Texture* texture) : Entity(_rect, texture), world(_world), scene(_scene)
{
	destination.x = catapultLocation.x - _rect.w * 0.5f;
	destination.y = catapultLocation.y - _rect.h * 0.5f;
}

void PlayerHandler::Render(SDL_Renderer* renderer)
{
	if (amount > 0) {
		SDL_SetRenderDrawColor(renderer, 0x5d, 0x40, 0x1a, 0xff);

		SDL_RenderDrawLine(renderer, catapultLocation.x - 10, catapultLocation.y, destination.x + source.w * 0.5, destination.y + source.h * 0.5);
		SDL_RenderDrawLine(renderer, catapultLocation.x + 10, catapultLocation.y, destination.x + source.w * 0.5, destination.y + source.h * 0.5);

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);

		Entity::Render(renderer);
	}
}

void PlayerHandler::Listen(SDL_Event event)
{
	if (amount > 0) {

		int mouseX, mouseY;
		switch (event.type)
		{
			case SDL_MOUSEBUTTONDOWN: {
				Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
				if (((mouseX > destination.x) && (mouseX < destination.x + destination.w) && (mouseY > destination.y) && (mouseY < destination.y + destination.h))) active = true;
			} break;
			case SDL_MOUSEMOTION: {

				Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

				if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) && active) {
					destination.y = max(0, min(mouseY - source.h * 0.5f, 800.0f - source.h));
					destination.x = max(0, min(mouseX - source.w * 0.5f, 1280.0f - source.w));
					float distToCatapult = b2Distance(catapultLocation, b2Vec2(mouseX, mouseY));
					if (distToCatapult > maxDistToCatapult) {
						destination.y = max(0, min(catapultLocation.y + (mouseY - catapultLocation.y) * maxDistToCatapult / distToCatapult - source.h * 0.5f, 800.0f - source.h));
						destination.x = max(0, min(catapultLocation.x + (mouseX - catapultLocation.x) * maxDistToCatapult / distToCatapult - source.w * 0.5f, 1280.0f - source.w));
					}
				}

			} break;
			case SDL_MOUSEBUTTONUP: {
				if (event.button.button == 1 && active) {
					std::shared_ptr<Player> newPlayer = std::make_shared<Player>(*world, BOX_ENTITY, destination, false,
						0.5f * PIXEL_TO_METER * (catapultLocation - (b2Vec2{ static_cast<float>(destination.x),
							static_cast<float>(destination.y) } +b2Vec2{ source.w * 0.5f, source.h * 0.5f }
					)), TextureManager::GetInstance()->GetTexture(currentTexture));

					currentTexture = textures[std::rand() % 3];
					Texture(TextureManager::GetInstance()->GetTexture(currentTexture));

					scene->AddEntity(newPlayer);
					destination.x = catapultLocation.x - source.w * 0.5f;
					destination.y = catapultLocation.y - source.h * 0.5f;
					active = false;
					amount--;
				}
			} break;
		}
	}
	return Entity::Listen(event);
}