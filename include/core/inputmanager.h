#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <map>
#include <vector>
#include <string>

class InputManager
{
public:
    enum KeyState
    {
        None,
        Pressed,
        Released,
        Pending
    };

public:
    static InputManager *getInstance();
    static void release();

    void mapKey(int, std::string, bool = false);

    bool isActionPressed(const char *);
    bool isActionReleased(const char *);
    bool isActionJustPressed(const char *);
    bool isActionJustReleased(const char *);

    bool isKeyPressed(SDL_Scancode);
    bool isMousePressed(int);
    void getMousePosition();

    void handleEvents(SDL_Event *);
    void update();
    void end();

private:
    static InputManager *instance;
    const Uint8 *keyboardState;

    std::map<int, std::string> keyMap;
    std::vector<std::string> actions;

    std::map<std::string, int> actionsPressed;
    std::map<std::string, int> actionsJustPressed;
    std::map<std::string, int> actionsJustReleased;

private:
    InputManager();
    ~InputManager();
};

#endif