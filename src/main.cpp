#include <iostream>
#include "game.h"
#include "texturemanager.h"

Game* game;

int main(int argc, char* args[]) {

	const int FPS = 60;
	const int frameDelay = 1000.0 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 176, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return 0;
}