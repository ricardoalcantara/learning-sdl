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

private:

	SDL_Rect src, dest;

	SDL_Texture* floor;
	SDL_Texture* air;

	int map[20][25];
};

#endif