#include "core/inputmanager.h"

#include <iostream>

InputManager *InputManager::instance = nullptr;

InputManager *InputManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new InputManager();
    }

    return instance;
}

void InputManager::release()
{
    delete instance;
    instance = nullptr;
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::isActionPressed(const char *)
{
    return false;
}

bool InputManager::isActionJustPressed(const char *)
{
    return false;
}

bool InputManager::isKeyPressed(SDL_Scancode scanCode)
{
    return keyboardState[scanCode];
}

bool InputManager::isMousePressed(int mouseButton)
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(mouseButton);
}

void InputManager::getMousePosition()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    std::cout << "Mouse " << x << ", " << y << std::endl;
}

void InputManager::update()
{
    keyboardState = SDL_GetKeyboardState(NULL);
}
