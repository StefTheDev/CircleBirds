#pragma once

#include "PhysicsEntity.h"
#include "TextureManager.h"

class WoodPlank : public PhysicsEntity
{
public:
	WoodPlank(b2World& _world, SDL_Rect _rect) : PhysicsEntity(_world, BOX_ENTITY, _rect, false, TextureManager::GetInstance()->GetTexture(WOOD_PLANK_SPRITE)) {
	
	}
};

