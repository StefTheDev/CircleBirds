#pragma once

#include "PhysicsEntity.h"
#include "TextureManager.h"

class WoodPlank : PhysicsEntity
{
public:
	WoodPlank(b2World& _world, SDL_Rect _rect) : PhysicsEntity(_world, BOX_ENTITY, _rect, false, TextureManager::GetInstance()->GetTexture(PLANK_WOOD_SPRITE)) {}
};

