#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL.h>

class GameState
{
public:
public:
    virtual void load() = 0;
    virtual bool isLoaded() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // !GAMESTATE;
