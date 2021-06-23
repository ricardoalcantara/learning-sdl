#include "core/gamestatemanager.h"
#include "core/gamestate.h"

GameStateManager::GameStateManager(Game* _game): game(_game)
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::loadState(const char*)
{
	if (currentGameState)
		currentGameState->load(game->renderer);
}

bool GameStateManager::isStateLoaded(const char*)
{
	return currentGameState && currentGameState->isLoaded();
}

void GameStateManager::selectState(const char*)
{

}
