#include "ui/label.h"
#include "core/assetsmanager.h"

Label::Label()
{
}

Label::Label(TTF_Font *font) : font(font)
{
}

Label::Label(const char *text, TTF_Font *font) : font(font)
{
    setText(text);
}

void Label::setText(const char *text)
{
    this->text = text;

    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, text, color);
    destRect.w = surfaceMessage->w;
    destRect.h = surfaceMessage->h;
    texture = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
}

const char *Label::getText()
{
    return text;
}

void Label::setColor(SDL_Color color)
{
    this->color = color;
}

SDL_Color Label::getColor()
{
    return color;
}

void Label::update()
{
    destRect.x = 10;
    destRect.y = 10;
}

void Label::render()
{
    SDL_RenderCopy(Game::renderer, texture, NULL, &destRect);
}