#ifndef SANDBOXSTATE_H
#define SANDBOXSTATE_H

#include "core/gamestate.h"
#include "core/gameobject.h"
// #include <SDL.h>

class SandboxState : public GameState
{
public:
    SandboxState();
    ~SandboxState();
    void load(SDL_Renderer *renderer) override;
    bool isLoaded() override;
    void update() override;
    void render() override;

public:
    GameObject *player;
};

#endif // !SANDBOXSTATE;
