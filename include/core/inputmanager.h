#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>

class InputManager
{
public:
    static InputManager *getInstance();
    static void release();

    bool isActionPressed(const char *);
    bool isActionJustPressed(const char *);
    bool isKeyPressed(SDL_Scancode);
    bool isMousePressed(int);
    void getMousePosition();

    void update();

private:
    static InputManager *instance;
    const Uint8* keyboardState;
private:
    InputManager();
    ~InputManager();
};

#endif