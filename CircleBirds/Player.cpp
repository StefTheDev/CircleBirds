#include "Player.h"

Player::Player(b2World& _world, SDL_Rect _rect) : Entity(_rect)
{
	mouseX = 0;
	mouseY = 0;

	b2BodyDef bodyDef;

	bodyDef.position.Set((_rect.x + _rect.w / 2.0f) * PIXEL_TO_METER, (_rect.y + _rect.h / 2.0f) * PIXEL_TO_METER);

	bodyDef.type = b2_dynamicBody;


	b2PolygonShape shapeBox;

	shapeBox.SetAsBox(_rect.w * PIXEL_TO_METER * 0.5f, _rect.h * PIXEL_TO_METER * 0.5f);

	b2FixtureDef fixtureDef;

	fixtureDef.shape = &shapeBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body = _world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);
}

Player::~Player()
{

}

void Player::Update()
{
	destination.x = body->GetPosition().x * METER_TO_PIXEL - source.w * 0.5f;
	destination.y = body->GetPosition().y * METER_TO_PIXEL - source.h * 0.5f;
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