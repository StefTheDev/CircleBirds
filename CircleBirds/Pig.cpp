#include "Pig.h"

Pig::Pig(b2World& _world, SDL_Rect _rect) : PhysicsEntity(_world, CIRCLE_ENTITY, _rect, false, TextureManager::GetInstance()->GetTexture(ENEMY_PIG_SPRITE))
{

}