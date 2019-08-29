#include "Level.h"

Level::Level()
{

}


Level::~Level()
{

}

bool Level::Initialise(b2Vec2 gravity, std::vector<std::shared_ptr<Entity>>& _entities)
{
	world = new b2World(gravity);
	if (world == nullptr) return false;

	entities = _entities;

	return true;
}

void Level::Render()
{
	for (auto& entity : entities) {
		entity->Render();
	}
}

void Level::Update()
{
	world->Step(DELTA_TIME, 8, 3);

	for (auto& entity : entities) {
		entity->Update();
	}
}

void Level::Listen(SDL_Event event)
{
	for (auto& entity : entities) {
		entity->Listen(event);
	}
}