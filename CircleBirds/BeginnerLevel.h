#pragma once

#include "Level.h"
#include "Player.h"

#include "SpriteManager.h"

class BeginnerLevel : public Level
{
public:
	BeginnerLevel();
	~BeginnerLevel();

	bool Initialise();
};

