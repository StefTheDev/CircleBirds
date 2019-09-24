#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(b2World& _world, SDL_Rect _rect, bool isStatic) : Entity(_rect)
{
	b2BodyDef bodyDef;

	bodyDef.position.Set((_rect.x + _rect.w / 2.0f) * PIXEL_TO_METER, (_rect.y + _rect.h / 2.0f) * PIXEL_TO_METER);

	bodyDef.type = isStatic ? b2_staticBody : b2_dynamicBody;


	b2PolygonShape shapeBox;

	shapeBox.SetAsBox(_rect.w * PIXEL_TO_METER, _rect.h * PIXEL_TO_METER);
	
	b2FixtureDef fixtureDef;

	fixtureDef.shape = &shapeBox;
	fixtureDef.density = isStatic ? 0.0f : 1.0f;
	fixtureDef.friction = 0.3f;

	body = _world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);

}

void PhysicsEntity::Update()
{
	position.x = body->GetPosition().x * METER_TO_PIXEL - source.w * 0.5f;
	position.y = body->GetPosition().y * METER_TO_PIXEL - source.h * 0.5f;
}
