#include "core/gamestatemanager.h"
#include "core/gamestate.h"

GameStateManager *GameStateManager::instance = nullptr;

GameStateManager *GameStateManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new GameStateManager();
	}

	return instance;
}

void GameStateManager::release()
{
	delete instance;
	instance = nullptr;
}

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

void GameStateManager::ready()
{
	currentGameState->ready();
}

void GameStateManager::handleEvents(SDL_Event *)
{

}

void GameStateManager::update()
{
	currentGameState->update();
}

void GameStateManager::render()
{
	currentGameState->render();
}
