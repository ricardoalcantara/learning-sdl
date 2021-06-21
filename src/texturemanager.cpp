#include "texturemanager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren) {
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if(!tempSurface) {
		printf("IMG_Load: %s\n", IMG_GetError());
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}