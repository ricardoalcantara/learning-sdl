#include "game/sandboxstate.h"
#include "core/gameobject.h"
#include "core/assetsmanager.h"
#include "core/game.h"
#include "audio/player.h"
#include "core/inputmanager.h"

#include <SDL_ttf.h>

SandboxState::SandboxState() : GameState()
{
    collisionWorld = new CollisionWorld(Rectangle(Vec2(0, 0), Vec2(320, 176)));
    entityManager = new EntityManager();

    std::vector<CollisionData *> data;

    TmpEntity player;
    player.collision = new CollisionData((void *)&player, Rectangle(Vec2(10, 10), Vec2(10, 10)));
    data.push_back(player.collision);
    entities.push_back(player);

    TmpEntity plataform1;
    plataform1.collision = new CollisionData((void *)&plataform1, Rectangle(Vec2(0, 150), Vec2(100, 10)));
    data.push_back(plataform1.collision);
    entities.push_back(plataform1);

    TmpEntity plataform2;
    plataform2.collision = new CollisionData((void *)&plataform2, Rectangle(Vec2(120, 150), Vec2(100, 10)));
    data.push_back(plataform2.collision);
    entities.push_back(plataform2);

    for (auto collisionData : data)
    {
        collisionWorld->Insert(*collisionData);
    }
}

SandboxState::~SandboxState()
{
}

void SandboxState::load()
{
}

void SandboxState::ready()
{
}

void SandboxState::update()
{
    Vec2 gravity = Vec2(0, 400);
    Vec2 velocity = Vec2();

    if (InputManager::getInstance()->isActionPressed("move_left"))
    {
        velocity.x -= 500;
    }

    if (InputManager::getInstance()->isActionPressed("move_right"))
    {
        velocity.x += 500;
    }

    if (InputManager::getInstance()->isActionJustPressed("jump"))
    {
        velocity.y -= 1500;
    }

    // Player
    entities[0].collision->bounds.position += (velocity + gravity) * 0.0167f;
    collisionWorld->Update(*entities[0].collision);
    std::vector<CollisionData *> collisionObjects = collisionWorld->Query(entities[0].collision->bounds);

    for (auto co : collisionObjects)
    {
        if (co != entities[0].collision)
        {
            if (RectangleOnRectangle(entities[0].collision->bounds, co->bounds))
            {
                entities[0].collision->bounds.position.y = co->bounds.position.y - entities[0].collision->bounds.size.y;
                collisionWorld->Update(*entities[0].collision);
            }
        }
    }

    // std::cout << "position y: " << entities[0].collision->bounds.position.y << std::endl;

    // if (entities[0].collision->bounds.position.y > 150)
    // {
    //     entities[0].collision->bounds.position.y = 150;
    // }
}

void SandboxState::render()
{
    for (auto entity : entities)
    {
        entity.render();
    }
}