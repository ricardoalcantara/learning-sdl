#include "core/gameobject.h"
#include "core/assetsmanager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
	objTexture = AssetsManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void GameObject::update() {
	xpos++;
	ypos++;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	//upscaled
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}