
#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H
#include "core/game.h"

#include <SDL_ttf.h>

class AssetsManager {
public:
	static SDL_Texture *LoadTexture(const char *fileName);
	static TTF_Font *LoadFont(const char *fileName, int size);

private:
};

#endif