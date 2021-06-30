#ifndef SANDBOXSTATE_H
#define SANDBOXSTATE_H

#include "core/gamestate.h"
#include "core/gameobject.h"
#include "entities/entity.h"
#include "entities/entitymanager.h"
#include "physics/quadtree.h"

class SandboxState : public GameState
{
public:
    struct TmpEntity
    {
        CollisionData *collision;

        TmpEntity() {}

        void update()
        {
        }

        void render()
        {
            SDL_Rect rect;
            rect.x = collision->bounds.position.x;
            rect.y = collision->bounds.position.y;
            rect.w = collision->bounds.size.x;
            rect.h = collision->bounds.size.y;

            SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(Game::renderer, &rect);
        }
    };

public:
    SandboxState();
    ~SandboxState();
    void load() override;
    void ready() override;
    void update() override;
    void render() override;

private:
    CollisionWorld *collisionWorld;
    EntityManager *entityManager;
    std::vector<TmpEntity> entities;
};

#endif // !SANDBOXSTATE;
