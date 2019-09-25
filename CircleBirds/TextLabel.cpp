#include "TextLabel.h"

TextLabel::TextLabel(std::function<void()> onClick, SDL_Rect rect, SDL_Texture* texture) : Entity(rect, texture)
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
	return ((x > destination.x) && (x < destination.x + destination.w) && (y > destination.y) && (y < destination.y + destination.h));
}

void TextLabel::click()
{
	return onClick();
}
