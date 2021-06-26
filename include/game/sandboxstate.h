#ifndef SANDBOXSTATE_H
#define SANDBOXSTATE_H

#include "core/gamestate.h"
#include "core/gameobject.h"
#include "ui/label.h"
#include "ui/button.h"
#include "audio/player.h"

class SandboxState : public GameState
{
public:
    SandboxState();
    ~SandboxState();
    void load() override;
    void ready() override;
    void update() override;
    void render() override;

private:
    GameObject *player;
    Label *label;
    Button *button;
    Player *audioPlayer;
};

#endif // !SANDBOXSTATE;
