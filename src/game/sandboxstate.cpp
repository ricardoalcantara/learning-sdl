#include "game/sandboxstate.h"
#include "core/gameobject.h"

SandboxState::SandboxState(): GameState()
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load(SDL_Renderer *renderer)
{
    player = new GameObject("assets/player.png", renderer);
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