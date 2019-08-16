#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Utilities.h"

class Scene
{
public:
	Scene(std::string string);
	~Scene();

	virtual bool Initialise();
	virtual void Render();
	virtual void Update();

	std::string ToString();

private:
	std::string string;

};

#endif
