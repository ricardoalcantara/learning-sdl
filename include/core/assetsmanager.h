
#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H
#include "core/game.h"

class AssetsManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
private:
};

#endif