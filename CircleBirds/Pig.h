#include "PhysicsEntity.h"
#include "TextureManager.h"

class Pig : public PhysicsEntity
{
public:
	Pig(b2World& _world, SDL_Rect _rect);
};