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
	TTF_Font *font;
	font = TTF_OpenFont(fileName, size);
	if (!font)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}

	return font;
}

void AssetsManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}