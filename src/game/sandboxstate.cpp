#include "game/sandboxstate.h"
#include "core/gameobject.h"
#include "core/assetsmanager.h"
#include "core/game.h"
#include "core/inputmanager.h"

#include <SDL_ttf.h>

SandboxState::SandboxState(): GameState()
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
    TTF_Font *font = AssetsManager::LoadFont("assets/fonts/Roboto/Roboto-Regular.ttf", 25);
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
    if (InputManager::getInstance()->isKeyPressed(SDL_SCANCODE_DOWN))
    {
        std::cout << "Key pressed" << std::endl;
    }

    if (InputManager::getInstance()->isMousePressed(SDL_BUTTON_LEFT))
    {
        InputManager::getInstance()->getMousePosition();
        std::cout << "Mouse pressed" << std::endl;
    }

    player->update();
    label->update();
}

void SandboxState::render()
{
    player->render();
    label->render();
    button->render();
}