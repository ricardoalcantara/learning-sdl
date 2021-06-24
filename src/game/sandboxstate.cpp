#include "game/sandboxstate.h"
#include "core/gameobject.h"
#include "core/texturemanager.h"
#include "core/game.h"

#include <SDL_ttf.h>

SandboxState::SandboxState(): GameState()
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
    TTF_Font *font = TextureManager::LoadFont("assets/fonts/Roboto/Roboto-Regular.ttf", 25);
    player = new GameObject("assets/player.png", 0 ,0);
    label = new Label("Hello world", font);
    button = new Button(10, 50, 100, 50);
}
bool SandboxState::isLoaded()
{
    return false;
}

void SandboxState::update()
{
    player->update();
    label->update();
}

void SandboxState::render()
{
    player->render();
    label->render();
    button->render();
}