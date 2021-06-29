#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "entities/entity.h"
#include "entities/component.h"

#include <vector>
#include <string>

class EntityManager {
private:
	std::vector<Entity*> entities;
public:
	void clearData();
	void update(float dt);
	void render();
	bool HasNoEntities();
	Entity& AddEntity(std::string entityName);
	std::vector<Entity*> getEntities() const;
	unsigned int getEntityCount();
};

#endif