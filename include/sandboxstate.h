#ifndef SANDBOXSTATE_H
#define SANDBOXSTATE_H

#include "gamestate.h"
#include "core/gameobject.h"
// #include <SDL.h>

class SandboxState : public GameState
{
public:
    SandboxState(SDL_Renderer * renderer);
    ~SandboxState();
    void load() override;
    bool isLoaded() override;
    void update() override;
    void render() override;

private:
    GameObject *player;
};

#endif // !SANDBOXSTATE;
