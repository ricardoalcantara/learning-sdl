#include "entities/entitymanager.h"

void EntityManager::clearData() {
	for (auto& entity:entities) {
		entity->destroy();
	}
}

bool EntityManager::HasNoEntities() {
	return entities.size() == 0;
}

void EntityManager::update(float dt) {
	for (auto& entity:entities) {
		entity->update(dt);
	}
}

void EntityManager::render() {
	for (auto& entity : entities) {
		entity->render();
	}
}

Entity& EntityManager::AddEntity(std::string entityName) {
	Entity* entity = new Entity(*this, entityName);
	entities.emplace_back(entity);
	return *entity;
}

unsigned int EntityManager::getEntityCount() {
	return entities.size();
}