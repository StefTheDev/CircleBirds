#include "TextLabel.h"



TextLabel::TextLabel() : Entity()
{
}


TextLabel::~TextLabel()
{
}

void TextLabel::Event(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {
			mouseX = event.motion.x;
			mouseY = event.motion.y;
		}
	}
	return Entity::Event(event);
}
