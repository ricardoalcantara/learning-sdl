#include "game/sandboxstate.h"
#include "core/gameobject.h"
#include "core/game.h"

SandboxState::SandboxState(): GameState()
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
    player = new GameObject("assets/player.png", 0 ,0);
}
bool SandboxState::isLoaded()
{
    return false;
}

void SandboxState::update()
{
    player->update();
}

void SandboxState::render()
{
    player->render();
}