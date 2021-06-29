#ifndef MAP_H
#define MAP_H
#include "core/game.h"

//to end

class Map {
public:
	Map();
	~Map();	

	void LoadMap(int arr[11][10]); //test
	void DrawMap();
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

private:

	SDL_Rect src, dest;

	SDL_Texture* floor;
	SDL_Texture* air;

	int map[20][25];
};

#endif