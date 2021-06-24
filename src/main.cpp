#include <iostream>
#include "core/game.h"
#include "core/assetsmanager.h"
#include "game/sandboxstate.h"
#include "game/mapstate.h"

Game* game;

enum GameStateEnum { Sandbox = 0, Map = 1 };

int main(int argc, char* args[]) {

	const int FPS = 60;
	const int frameDelay = 1000.0 / FPS;

	Uint32 frameStart;
	int frameTime;
	std::cout << SDL_GetBasePath() << std::endl;
	game = new Game();
	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 176, false);

	game->GetGameStateManager()->addState( GameStateEnum::Sandbox, new SandboxState());
	game->GetGameStateManager()->addState( GameStateEnum::Map, new MapState());
	
	// Should load only one at time
	game->GetGameStateManager()->loadState(GameStateEnum::Sandbox);
	game->GetGameStateManager()->loadState(GameStateEnum::Map);

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