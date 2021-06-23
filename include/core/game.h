#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "gamestate.h"

class Game {
public: 
	Game(); // constructor
	~Game(); // destroyer

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);

	template <typename T>
	void addState(const char*);
	void loadState(const char*);
	bool isStateLoaded(const char*);
	void selectState(const char*);

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
	bool isRunning;
	SDL_Window* window;
<<<<<<< HEAD:include/core/game.h
=======
	SDL_Renderer* renderer;
	GameState* currentGameState;
>>>>>>> 69a4aca (Begin implementation):include/game/game.h
};

#endif 