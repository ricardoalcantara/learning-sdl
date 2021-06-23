#include "core/game.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void update();
	void render();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

#endif // !GAME_OBJECT;
