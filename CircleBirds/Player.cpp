#include "Player.h"

Player::Player(b2World& _world,SDL_Rect _rect, b2Vec2 initialForce, SDL_Texture* texture) : PhysicsEntity(_world, CIRCLE_ENTITY, _rect, false, texture)
{
	
	mouseX = 0;
	mouseY = 0;
	body->ApplyLinearImpulseToCenter(initialForce, true);

}

Player::~Player()
{

}

void Player::Update()
{
	destination.x = body->GetPosition().x * METER_TO_PIXEL - source.w * 0.5f;
	destination.y = body->GetPosition().y * METER_TO_PIXEL - source.h * 0.5f;
	angle = body->GetAngle() * (1.0f/0.01745329252f);
	Entity::Update();
}