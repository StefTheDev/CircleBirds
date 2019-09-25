#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(b2World& _world, EntityType entityType, SDL_Rect _rect, bool isStatic) : Entity(_rect)
{
	b2BodyDef bodyDef;

	bodyDef.position.Set((_rect.x + _rect.w / 2.0f) * PIXEL_TO_METER, (_rect.y + _rect.h / 2.0f) * PIXEL_TO_METER);

	bodyDef.type = isStatic ? b2_staticBody : b2_dynamicBody;

	b2FixtureDef fixtureDef;

	b2CircleShape circleShape;
	b2PolygonShape boxShape;

	switch (entityType)
	{
	case CIRCLE_ENTITY: {
		circleShape.m_p = b2Vec2(0.0f, 0.0f);
		circleShape.m_radius = (_rect.w * PIXEL_TO_METER * 0.5f) - 0.01f;
		fixtureDef.shape = &circleShape;
	} break;
	case BOX_ENTITY: {
		boxShape.SetAsBox((_rect.w * PIXEL_TO_METER * 0.5f) - 0.01f, (_rect.h * PIXEL_TO_METER * 0.5f) -0.01f);
		fixtureDef.shape = &boxShape;
	} break;

	}

	fixtureDef.density = isStatic ? 0.0f : 1.0f;
	fixtureDef.friction = 1.0f;

	body = _world.CreateBody(&bodyDef);
	body->SetAngularDamping(0.2f);
	body->SetLinearDamping(0.2f);
	body->CreateFixture(&fixtureDef);
}

void PhysicsEntity::Update()
{
	destination.x = body->GetPosition().x * METER_TO_PIXEL - source.w * 0.5f;
	destination.y = body->GetPosition().y * METER_TO_PIXEL - source.h * 0.5f;
	angle = body->GetAngle() * (1.0f / 0.01745329252f);
}

b2Body* PhysicsEntity::GetBody()
{
	return body;
}
