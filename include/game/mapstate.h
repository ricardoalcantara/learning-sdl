#ifndef MAPSTATE_H
#define MAPSTATE_H

#include "core/gamestate.h"
#include "core/gameobject.h"
#include "core/map.h"

class MapState : public GameState
{
public:
    MapState();
    ~MapState();
    void load() override;
    bool isLoaded() override;
    void update() override;
    void render() override;

public:
    GameObject *player;
    Map* map;
};

#endif // !MAPSTATE;
