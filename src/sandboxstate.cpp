#include "sandboxstate.h"
#include "core/gameobject.h"

SandboxState::SandboxState(SDL_Renderer *renderer) : GameState(renderer)
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
    player = new GameObject("assets/player.png", this->renderer);
}
bool SandboxState::isLoaded()
{
    return false;
}

void SandboxState::update()
{
}
void SandboxState::render()
{
}