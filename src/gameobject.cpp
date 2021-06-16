#include "gameobject.h"
#include "texturemanager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
}

void GameObject::update() {

	xpos++;
	ypos++;

	srcRect.w = 64;
	srcRect.h = 48;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	//maybe ^^ srcRect.w * 2
}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}