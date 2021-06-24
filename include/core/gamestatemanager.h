#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <map>
#include "core/game.h"

class Game;
class GameState;

class GameStateManager
{
public:
    GameStateManager();
    ~GameStateManager();

	void addState(int, GameState*);
	void loadState(int);
	bool isStateLoaded(int);
	void selectState(int);
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
