#pragma once
#include "Player.h"
#include "GameScene.h"

class PlayerHandler : public Entity
{
public:
	PlayerHandler(SDL_Rect _rect, b2World* _world, std::shared_ptr<Scene> _scene, SDL_Texture* texture);
	void Render(SDL_Renderer * renderer) override;
	void Listen(SDL_Event event) override;
private:
	b2World* world;
	std::shared_ptr<Scene> scene;
	b2Vec2 catapultLocation{ (120 + 32 * 0.5) + 5, 550 + 10};
	float maxDistToCatapult = 100.0f;
	int amount = 5;
	bool active = false;

	SpriteTexture textures[3] = { PLAYER_RED_SPRITE, PLAYER_CHUCK_SPRITE, PLAYER_BLUEY_SPRITE };
	SpriteTexture currentTexture = PLAYER_RED_SPRITE;
};

