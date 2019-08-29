#pragma once

#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool Initialise(Vector2 position);
	virtual void Render(SDL_Renderer * renderer);
	virtual void Listen(SDL_Event event) {}
	virtual void Update();

	void SetSprite(std::shared_ptr<Sprite> sprite);

	void Transform(Vector2 position);
	void Rotate(float angle);

private:

	Vector2 position;
	float angle;

	std::shared_ptr<Sprite> sprite;
	SDL_Rect source, destination;
};
