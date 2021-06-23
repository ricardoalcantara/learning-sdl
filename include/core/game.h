#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "core/gamestate.h"
#include "core/gamestatemanager.h"

class GameStateManager;

class Game {
public: 
	Game(); // constructor
	~Game(); // destroyer

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clear();

	bool running() {
		return isRunning;
	}
	static SDL_Renderer* renderer;


	GameStateManager* GetGameStateManager() const
	{
		return gameStateManager;
	}

private:
	int ticker = 0;
	bool isRunning;
	SDL_Window* window;
<<<<<<< HEAD:include/core/game.h
<<<<<<< HEAD:include/core/game.h
=======
	SDL_Renderer* renderer;
	GameState* currentGameState;
>>>>>>> 69a4aca (Begin implementation):include/game/game.h
=======
	GameStateManager* gameStateManager;
public:
	SDL_Renderer* renderer;
>>>>>>> 75f82dd (running):include/game/game.h
};

#endif 