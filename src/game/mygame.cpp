#include "game/mygame.h"
#include "core/gamestatemanager.h"
#include "game/mapstate.h"
#include "game/sandboxstate.h"

void MyGame::init(const char* title, int x, int y, int scale, bool fullscreen)
{
    Game::init(title, x, y, scale, fullscreen);

    GameStateManager::getInstance()->addState(GameStateEnum::Sandbox, new SandboxState());
	GameStateManager::getInstance()->addState(GameStateEnum::Map, new MapState());

	// Should load only one at time
	GameStateManager::getInstance()->loadState(GameStateEnum::Sandbox);
	GameStateManager::getInstance()->loadState(GameStateEnum::Map);

	GameStateManager::getInstance()->ready();
}

void MyGame::update()
{
    Game::update();
}

void MyGame::render()
{
    Game::render();
}
