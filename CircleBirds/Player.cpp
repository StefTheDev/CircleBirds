#include "Player.h"

Player::Player(b2World& _world, SDL_Rect _rect, b2Vec2 initialForce) : Entity(_rect)
{
	mouseX = 0;
	mouseY = 0;

	b2BodyDef bodyDef;

	bodyDef.position.Set((_rect.x + _rect.w / 2.0f) * PIXEL_TO_METER, (_rect.y + _rect.h / 2.0f) * PIXEL_TO_METER);

	bodyDef.type = b2_dynamicBody;

	b2CircleShape shapeBox;

	shapeBox.m_p = b2Vec2(0.0f, 0.0f);
	shapeBox.m_radius = _rect.w * PIXEL_TO_METER * 0.5f;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shapeBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;

	body = _world.CreateBody(&bodyDef);
	body->SetAngularDamping(0.2f);
	body->SetLinearDamping(0.2f);
	body->CreateFixture(&fixtureDef);

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