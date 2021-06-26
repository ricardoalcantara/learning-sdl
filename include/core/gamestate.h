#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL.h>

class GameState
{
public:
    virtual void load(){};
    virtual void ready(){};
    virtual bool isLoaded() { return false; };
    virtual void update(){};
    virtual void render(){};
};

#endif // !GAMESTATE;
