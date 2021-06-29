#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

class Component;
class EntityManager;

class Entity {
private:
	EntityManager& manager;
	bool isActive;
	std::vector<Component*> components;
public:
	std::string name;
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);
	void update(float dt);
	void render();
	void destroy();
	bool isActive() {
		return isActive;
	}
};

#endif