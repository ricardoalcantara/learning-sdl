#ifndef SANDBOXSTATE_H
#define SANDBOXSTATE_H

#include "core/gamestate.h"
#include "core/gameobject.h"
#include "ui/label.h"
#include "ui/button.h"

class SandboxState : public GameState
{
public:
    SandboxState();
    ~SandboxState();
    void load() override;
    bool isLoaded() override;
    void update() override;
    void render() override;

public:
    GameObject *player;
    Label *label;
    Button *button;
};

#endif // !SANDBOXSTATE;
