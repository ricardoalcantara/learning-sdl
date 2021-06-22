#include "game.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren);
	~GameObject();

	void update();
	void render();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

#endif // !GAME_OBJECT;
