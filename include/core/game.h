#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "core/gamestatemanager.h"
#include "core/gamestate.h"
#include "core/inputmanager.h"

class GameStateManager;

class Game
{
public:
	Game();	 // constructor
	~Game(); // destroyer

	void handleEvents();
	virtual void init(const char *title, int x, int y, int scale, bool fullscreen);
	virtual void update();
	virtual void render();
	virtual void loop();
	void clear();

	bool running()
	{
		return isRunning;
	}

	static SDL_Renderer *renderer;

	int ticksLastFrame = 0;
	float deltaTime = 0;
	const char *title;

private:
	int ticker = 0;
	int scale = 1;
	bool isRunning;

	const int FPS = 60;
	int frameDelay = 1000.0 / FPS;

	SDL_Window *window;
	GameStateManager *gameStateManager;
	InputManager *inputManager;
};

#endif