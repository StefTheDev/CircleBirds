#pragma once
#include "Scene.h"
#include "TextLabel.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	bool Load() override;
};

