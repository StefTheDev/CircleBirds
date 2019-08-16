#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"

class Entity
{
public:
	Entity();
	~Entity();

private:
	std::unique_ptr<Sprite> sprite;
};

#endif
