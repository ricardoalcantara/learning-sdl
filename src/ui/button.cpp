#include "ui/button.h"
#include "core/game.h"

Button::Button(int x, int y, int width, int height)
{
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;
}

Button::~Button()
{
}

void Button::update()
{
}

void Button::render()
{
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &destRect);
}
