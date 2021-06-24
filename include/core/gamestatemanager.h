#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <map>
#include "game/game.h"

class Game;
class GameState;

class GameStateManager
{
public:
    GameStateManager(Game*);
    ~GameStateManager();

	void addState(int, GameState*);
	void loadState(int);
	bool isStateLoaded(const char*);
	void selectState(const char*);
	GameState* getCurrentState()
	{
		return currentGameState;
	}
private:
	Game* game;
	std::map<int, GameState*> gameStates;
	GameState* currentGameState;

};

#endif // !GAMESTATEMANAGER;
