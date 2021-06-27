#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <map>
#include <SDL.h>

#include "core/game.h"
#include "core/gamestate.h"

class GameStateManager
{
public:
	static GameStateManager *getInstance();
	static void release();

	void addState(int, GameState *);
	void loadState(int);
	bool isStateLoaded(int);
	void selectState(int);
	GameState *getCurrentState()
	{
		return currentGameState;
	}

	void ready();
	void handleEvents(SDL_Event *);
	void update();
	void render();

private:
	static GameStateManager *instance;
	std::map<int, GameState *> gameStates;
	GameState *currentGameState;

private:
	GameStateManager();
	~GameStateManager();
};

#endif // !GAMESTATEMANAGER;
