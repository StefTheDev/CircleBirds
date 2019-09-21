#pragma once
#include "Entity.h"

class TextLabel : public Entity
{
public:
	TextLabel(std::string label, std::function<void()> onClick);
	~TextLabel();

	void Load(TTF_Font* font, Vector2 vector);
	void Listen(SDL_Event event) override;
	void Render(SDL_Renderer * renderer) override; 
	bool IsHover(int x, int y) const;

private:

	void click();
	Vector2 position;

	std::string label;
	std::function<void()> onClick;


	TTF_Font* font;

	SDL_Color color;
};

