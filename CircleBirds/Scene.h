#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Utilities.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual bool Initialise();
	virtual void Render();
	virtual void Update();

};

#endif
