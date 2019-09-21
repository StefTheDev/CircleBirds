#include "TextLabel.h"

TextLabel::TextLabel(std::function<void()> onClick)
{
	this->onClick = onClick;
}

TextLabel::~TextLabel()
{

}


void TextLabel::Listen(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {
			if (IsHover(event.motion.x, event.motion.y)) {
				SDL_SetTextureColorMod(texture, 150, 150, 150);
			}
			else {
				SDL_SetTextureColorMod(texture, 50, 50, 50);
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {

			if (IsHover(event.motion.x, event.motion.y)) click();
			break;
		}
	}
	return Entity::Listen(event);
}

bool TextLabel::IsHover(int x, int y) const
{
	return ((x > position.x) && (x < position.x + destination.w) && (y > position.y) && (y < position.y + destination.h));
}

void TextLabel::click()
{
	return onClick();
}
