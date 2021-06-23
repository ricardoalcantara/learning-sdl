#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL.h>

class GameState
{
public:
    SDL_Renderer *renderer;
public:
    GameState(SDL_Renderer * renderer):renderer(renderer) {}
    virtual void load() = 0;
    virtual bool isLoaded() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // !GAMESTATE;
