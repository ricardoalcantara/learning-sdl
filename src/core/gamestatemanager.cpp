#include "core/gamestatemanager.h"
#include "core/gamestate.h"

GameStateManager::GameStateManager(Game *_game) : game(_game)
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
	}

	if (currentGameState)
		currentGameState->load(game->renderer);
}

bool GameStateManager::isStateLoaded(const char *)
{
	return currentGameState && currentGameState->isLoaded();
}

void GameStateManager::selectState(const char *)
{
}
