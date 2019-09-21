#include "FontManager.h"

std::shared_ptr<FontManager> FontManager::fontManager = nullptr;

FontManager::FontManager()
{

}


FontManager::~FontManager()
{

}
void FontManager::Load()
{
	fonts.push_back(TTF_OpenFont("Resources/Fonts/ARIAL_BOLD.TTF", 600));
}

TTF_Font * FontManager::Font(FontType fontType)
{
	if (fontType < 0 || fontType >= fonts.size()) return nullptr;
	return fonts[fontType];
}

std::shared_ptr<FontManager> FontManager::GetInstance()
{
	if (fontManager == nullptr) {
		fontManager = std::make_shared<FontManager>();
		fontManager->Load();
	}
	return fontManager;
}
