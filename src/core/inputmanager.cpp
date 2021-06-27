#include "core/inputmanager.h"

#include <iostream>
#include <algorithm>

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

void InputManager::mapKey(int key, std::string action, bool replace)
{
    if (replace)
    {
        keyMap.erase(key);
    }
    
    keyMap.insert(std::make_pair(key, action));
    auto search = std::find(actions.begin(), actions.end(), action);
    if (search == actions.end())
    {
        actions.push_back(action);
    }
}

bool InputManager::isActionPressed(const char *action)
{
    return actionsPressed[action] == KeyState::Pressed;
}

bool InputManager::isActionReleased(const char *action)
{
    return actionsPressed[action] == KeyState::Released;
}

bool InputManager::isActionJustPressed(const char *action)
{
    return actionsJustPressed[action] == KeyState::Pressed;
}

bool InputManager::isActionJustReleased(const char *action)
{
    return actionsJustReleased[action] == KeyState::Released;
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

void InputManager::handleEvents(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_KEYDOWN:
    {
        auto search = keyMap.find(event->key.keysym.sym);
        if (search != keyMap.end())
        {
            auto action = search->second;
            actionsPressed[action] = KeyState::Pressed;
            if (actionsJustPressed[action] == KeyState::None)
            {
                actionsJustPressed[action] = KeyState::Pressed;
            }
        }
        break;
    }
    case SDL_KEYUP:
    {
        auto search = keyMap.find(event->key.keysym.sym);
        if (search != keyMap.end())
        {
            auto action = search->second;
            actionsPressed[action] = KeyState::Released;
            actionsJustReleased[action] = KeyState::Released;
            if (actionsJustPressed[action] == KeyState::Pending)
            {
                actionsJustPressed[action] = KeyState::Released;
            }
        }
        break;
    }
    default:
        break;
    }
}

void InputManager::update()
{
    keyboardState = SDL_GetKeyboardState(NULL);
}

void InputManager::end()
{
    for (auto const &action : actions)
    {
        if (actionsJustPressed[action] == KeyState::Pressed)
        {
            actionsJustPressed[action] = KeyState::Pending;
        }

        if (actionsJustPressed[action] == KeyState::Released)
        {
            actionsJustPressed[action] = KeyState::None;
        }

        if (actionsJustReleased[action] == KeyState::Released)
        {
            actionsJustReleased[action] = KeyState::None;
        }

        if (actionsPressed[action] == KeyState::Released)
        {
            actionsPressed[action] = KeyState::None;
        }
    }
}
