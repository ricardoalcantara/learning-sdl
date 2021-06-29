#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include "core/component.h"

class Component;
class EntityManager;

class Entity {
private:
	EntityManager& manager;
	bool activated;
	std::vector<Component*> components;
public:
	std::string name;
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);
	void update(float dt);
	void render();
	void destroy();
	bool isActive() {
		return activated;
	}
};

#endif