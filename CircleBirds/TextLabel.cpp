#include "TextLabel.h"

TextLabel::TextLabel(std::string label, std::function<void()> onClick)
{
	this->label = label;
	this->onClick = onClick;
}

TextLabel::~TextLabel()
{

}

void TextLabel::Load(TTF_Font * font, Vector2 vector)
{
	this->font = font;
	this->position = vector;
	Entity::Load(SDL_Rect{});
}

void TextLabel::Listen(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {
			color = SDL_Color { 255, 0, 255 };
			if (IsHover(event.motion.x, event.motion.y)) color = SDL_Color{ 255, 255, 255};
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			if (IsHover(event.motion.x, event.motion.y)) click();
			break;
		}
	}
	return Entity::Listen(event);
}

void TextLabel::Render(SDL_Renderer * renderer)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, label.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	this->texture = texture;
	int width, height = 0;
	SDL_QueryTexture(this->texture, NULL, NULL, &width, &height);

	Entity::Render(renderer);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

bool TextLabel::IsHover(int x, int y) const
{
	return ((x > position.x) && (x < position.x + dimension.x) && (y > position.y) && (y < position.y + dimension.y));
}

void TextLabel::click()
{
	return onClick();
}
