#pragma once

#include "PhysicsEntity.h"
#include "TextureManager.h"

class StoneBrick: PhysicsEntity
{
public:
	StoneBrick(b2World& _world, SDL_Rect _rect) : PhysicsEntity(_world, BOX_ENTITY, _rect, false, TextureManager::GetInstance()->GetTexture(PLATFORM_STONE_SPRITE)) {}
};
