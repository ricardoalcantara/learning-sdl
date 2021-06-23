#include "core/gameobject.h"
#include "core/texturemanager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

void GameObject::update() {
	xpos = 0;
	ypos = 0;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}