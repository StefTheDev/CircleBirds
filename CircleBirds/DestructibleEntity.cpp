#include "DestructibleEntity.h"

DestructibleEntity::DestructibleEntity(b2World& _world, EntityType entityType, SDL_Rect _rect, SDL_Texture* texture, float _health) : PhysicsEntity(_world, entityType, _rect, false, texture), health(_health)
{
}

bool DestructibleEntity::dealDamage(float damage)
{
	return (health-=damage) <= 0.0f;
}
