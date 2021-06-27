#include <iostream>
#include "game/mygame.h"

int main(int argc, char *args[])
{
	MyGame *game = new MyGame();
	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2, false);
	game->loop();
	
	return 0;
}