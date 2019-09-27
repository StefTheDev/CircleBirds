#include "Enemy.h"

Enemy::Enemy(b2World& _world, SDL_Rect _rect, SDL_Texture* texture) : PhysicsEntity(_world, CIRCLE_ENTITY, _rect, false, texture)
{
	
}

Enemy::~Enemy()
{
}