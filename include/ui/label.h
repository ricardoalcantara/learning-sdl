#ifndef LABEL_H
#define LABEL_H

#include "ui/uielement.h"
#include <SDL.h>
#include <SDL_ttf.h>

class Label : public UIElement
{
public:
    Label();
    Label(TTF_Font *);
    Label(const char*, TTF_Font *);
    ~Label();

    void setText(const char *);
    const char *getText();
    void setColor(SDL_Color);
    SDL_Color getColor();

    void update();
    void render();

private:
    SDL_Color color = {0, 0, 0};
    TTF_Font *font;
    const char *text;
    SDL_Texture *texture;
    SDL_Rect destRect;
};

#endif