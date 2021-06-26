#include "game/sandboxstate.h"
#include "core/gameobject.h"
#include "core/assetsmanager.h"
#include "core/game.h"
#include "audio/player.h"
#include "core/inputmanager.h"

#include <SDL_ttf.h>

enum Musics
{
    intro = 0
};

SandboxState::SandboxState() : GameState()
{
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
    TTF_Font *font = AssetsManager::LoadFont("assets/fonts/Roboto/Roboto-Regular.ttf", 25);
    label = new Label("Hello world", font);

    player = new GameObject("assets/player.png", 0, 0);
    button = new Button(10, 50, 100, 50);

    Mix_Music *music = AssetsManager::LoadMusic("assets/audio/5 Action Chiptunes By Juhani Junkala/Juhani Junkala [Retro Game Music Pack] Title Screen.wav");
    audioPlayer = new Player();
    audioPlayer->addMusic(Musics::intro, music);
}

void SandboxState::ready()
{
    audioPlayer->playMusic(Musics::intro);
    audioPlayer->setMusicVolume(40);
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