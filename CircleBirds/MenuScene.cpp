#include "MenuScene.h"



MenuScene::MenuScene()
{
}


MenuScene::~MenuScene()
{
}

bool MenuScene::Initialise()
{
	std::cout << "Menu Scene Initialised" << std::endl;
	return true;
}

void MenuScene::Render()
{
	std::cout << "Menu Scene Rendering" << std::endl;
	Sleep(500);
}

void MenuScene::Update()
{
	std::cout << "Menu Scene Updating" << std::endl;
	Sleep(500);
}
