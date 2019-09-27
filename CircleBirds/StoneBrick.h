#pragma once

#include "PhysicsEntity.h"
#include "TextureManager.h"

class StoneBrick: public PhysicsEntity
{
public:
	StoneBrick(b2World& _world, SDL_Rect _rect) : PhysicsEntity(_world, BOX_ENTITY, _rect, false, TextureManager::GetInstance()->GetTexture(STONE_BRICK_SPRITE)) {
	
		b2MassData data;
		data.center = b2Vec2{ 0.0f, 0.0f};
		data.mass = 2.0f;
		body->SetMassData(&data);
	}
};
