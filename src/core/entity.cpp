#include "core/entity.h"

Entity::Entity(EntityManager& manager):manager(manager) {
	this->activated = true;
}

Entity::Entity(EntityManager& manager, std::string name) : manager(manager), name(name) {
	this->activated = true;
}

void Entity::update(float dt) {
	for (auto& component : components) {
		component->update(dt);
	}
}

void Entity::render() {
	for (auto& component : components) {
		component->render();
	}
}

void Entity::destroy() {
	this->activated = false;
}