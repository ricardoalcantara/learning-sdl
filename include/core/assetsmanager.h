
#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H
#include "core/game.h"

#include <SDL_ttf.h>
#include <SDL_mixer.h>

class AssetsManager
{
public:
	static SDL_Texture *LoadTexture(const char *fileName);
	static TTF_Font *LoadFont(const char *fileName, int size);
	static Mix_Chunk *LoadSample(const char *fileName);
	static Mix_Music *LoadMusic(const char *fileName);

private:
};

#endif