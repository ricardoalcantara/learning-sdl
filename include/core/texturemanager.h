#include "game/game.h"

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class TextureManager {
public:
	//this could be static
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
private:
};

#endif