#include "game/mapstate.h"
#include "core/gameobject.h"
#include "core/game.h"

MapState::MapState(): GameState()
{
}

MapState::~MapState()
{
}

void MapState::load()
{
    player = new GameObject("assets/player.png", 0 ,0);
    map = new Map();
}
bool MapState::isLoaded()
{
    return false;
}

void MapState::update()
{
    player->update();
}

void MapState::render()
{
    map->DrawMap();
    player->render();
}