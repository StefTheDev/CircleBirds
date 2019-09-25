#pragma once
#include "Entity.h"

class TextLabel : public Entity
{
public:
	TextLabel(std::function<void()> onClick, SDL_Rect rect, SDL_Texture* texture);
	~TextLabel();
	void Listen(SDL_Event event) override;
	bool IsHover(int x, int y) const;

private:
	void click();
	std::function<void()> onClick;
};

