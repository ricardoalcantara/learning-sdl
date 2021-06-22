#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

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

private:
	int ticker;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;


};

#endif 