#include "core/game.h"

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL_ttf.h>

class TextureManager
{
public:
	static SDL_Texture *LoadTexture(const char *fileName);
	static TTF_Font *LoadFont(const char *fileName, int size);
	static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

private:
};

#endif