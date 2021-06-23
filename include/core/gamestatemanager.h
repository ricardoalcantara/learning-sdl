#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "game/game.h"

class Game;
class GameState;

class GameStateManager
{
public:
    GameStateManager(Game*);
    ~GameStateManager();

	template <class T>
	void addState(const char*)
	{
		currentGameState = new T();
	}
	void loadState(const char*);
	bool isStateLoaded(const char*);
	void selectState(const char*);
	GameState* getCurrentState()
	{
		return currentGameState;
	}
private:
	Game* game;
	GameState* currentGameState;

};

#endif // !GAMESTATEMANAGER;
