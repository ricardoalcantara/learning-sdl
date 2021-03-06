#include "core/map.h"
#include "core/assetsmanager.h"

//level test

int tilesize = 8;
int lvl1[11][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0 is air
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1} // 1 is floor
};

void Map::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

Map::Map() {
	floor = AssetsManager::LoadTexture("assets/testFloor.png");
	air = AssetsManager::LoadTexture("assets/testAir.png");

	LoadMap(lvl1); // test
	src.x = 0;
	src.y = 0;
	src.w = dest.w = tilesize;
	src.h = dest.h = tilesize;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[11][10]) { // test
	for (int row = 0; row < 11; row++) {
		for (int column = 0; column < 10; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int tileIndex = 0;
	for (int row = 0; row < 11; row++) {
		for (int column = 0; column < 10; column++) {
			tileIndex = lvl1[row][column]; //get tile index
			dest.x = column * tilesize;
			dest.y = row * tilesize;
			switch (tileIndex)
			{
			case 0:
				Map::Draw(air, src, dest);
				break;
			case 1:
				Map::Draw(floor, src, dest);
				break;
			default:
				break;
			}
		}
	}
}