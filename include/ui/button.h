#ifndef BUTTON_H
#define BUTTON_H

#include "ui/uielement.h"
#include <SDL.h>

class Button : public UIElement
{
public:
    Button(int, int, int, int);
    ~Button();

    void update();
    void render();

private:
    SDL_Color color = {0, 0, 0};
    SDL_Texture *texture;
    SDL_Rect destRect;
};

#endif