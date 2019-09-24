#pragma once
#include "Player.h"
#include "GameScene.h"

class PlayerHandler : public Entity
{
public:
	PlayerHandler(SDL_Rect _rect, b2World * _world, std::shared_ptr<Scene> _scene);
	void Render(SDL_Renderer * renderer) override;
	void Listen(SDL_Event event) override;
private:
	b2World* world;
	std::shared_ptr<Scene> scene;
	b2Vec2 catapultLocation{ 200.0f, 450.0f };
	float maxDistToCatapult = 100.0f;
	bool active = false;
};

