#include "TextLabel.h"


TextLabel::~TextLabel()
{
}

void TextLabel::Listen(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {
			mouseX = event.motion.x;
			mouseY = event.motion.y;
		}
	}
	return Entity::Listen(event);
}
