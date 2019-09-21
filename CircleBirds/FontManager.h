#pragma once

#include "Utilities.h"

enum FontType {
	ARIAL_FONT
};

class FontManager
{
public:
	FontManager();
	~FontManager();


	static std::shared_ptr<FontManager> GetInstance();

	void Load();

	TTF_Font * Font(FontType fontType);

private:
	std::vector<TTF_Font*> fonts;

protected:

	static std::shared_ptr<FontManager> fontManager;
};

