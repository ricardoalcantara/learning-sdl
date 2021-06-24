#include "core/gamestatemanager.h"
#include "core/gamestate.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::addState(int id, GameState *gameState)
{
	auto search = gameStates.find(id);
	if (search != gameStates.end())
	{
		// Todo: Clean
	}
	gameStates.insert(std::make_pair(id, gameState));
}

void GameStateManager::loadState(int id)
{
	auto search = gameStates.find(id);
	if (search != gameStates.end())
	{
		currentGameState = search->second;
		currentGameState->load();
	}
}

bool GameStateManager::isStateLoaded(int id)
{
	return currentGameState && currentGameState->isLoaded();
}

void GameStateManager::selectState(int id)
{
	auto search = gameStates.find(id);
	if (search != gameStates.end())
	{
		currentGameState = search->second;
	}
}
