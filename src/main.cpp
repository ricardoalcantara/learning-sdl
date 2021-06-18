#include <SDL.h>
#include <iostream>
#include "game.h"

Game* game;

int main(int argc, char* args[]) {
	game = new Game();

	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 176, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	
	//game->clear();
	return 0;
}