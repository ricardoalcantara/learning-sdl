#include "core/assetsmanager.h"

SDL_Texture* AssetsManager::LoadTexture(const char* fileName) {
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if(!tempSurface) {
		printf("IMG_Load: %s\n", IMG_GetError());
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}