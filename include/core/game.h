#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "core/gamestatemanager.h"
#include "core/gamestate.h"
#include "core/inputmanager.h"

class GameStateManager;

class Game {
public: 
	Game(); // constructor
	~Game(); // destroyer

	void init(const char* title, int x, int y, int scale, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clear();

	bool running() {
		return isRunning;
	}

	static SDL_Renderer* renderer;

private:
	int ticker = 0;
	int scale = 1;
	bool isRunning;

	SDL_Window* window;
	GameStateManager* gameStateManager;
	InputManager *inputManager;
};

#endif 