#include "core/assetsmanager.h"

SDL_Texture *AssetsManager::LoadTexture(const char *fileName)
{
	SDL_Surface *tempSurface = IMG_Load(fileName);

	if (!tempSurface)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

TTF_Font *AssetsManager::LoadFont(const char *fileName, int size)
{
	auto font = TTF_OpenFont(fileName, size);
	if (!font)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}

	return font;
}

Mix_Chunk *AssetsManager::LoadSample(const char *fileName)
{
	auto wave = Mix_LoadWAV(fileName);
	if (wave == NULL)
	{
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		return nullptr;
	}

	return wave;
}

Mix_Music *AssetsManager::LoadMusic(const char *fileName)
{
	auto music = Mix_LoadMUS(fileName);
	if (music == NULL)
	{
		printf("Mix_LoadMUS: %s\n", Mix_GetError());
		return nullptr;
	}

	return music;
}
