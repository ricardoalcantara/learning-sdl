#ifndef ENTITY_H
#define ENTITY_H

#include "ECS.h"
#include <vector>
#include <memoty>
#include "component.h"

class Entity {
public:
	Entity(){}
	virtual ~Entity(){}

	template<typename T, typename... TArgs>
	inline T& addComponent(TArgs&& ... args) {
		T* comp(new T(std::forward<TArgs>[args]...));
		std::unique_ptr<Component> uptr { comp };
		components.emplace_back(std::move(uptr));

		if (comp->init()) {
			compList[getComponentTypeID<T>()] = comp;
			compBitset[getComponentTypeID<T>()] = true;
			comp->entity = this;
			return *comp;
		}

		return *static_cast<T*>(nullptr);
	}

	template<Typename T>
	inline T& getComponent() const {
		auto prt(compList[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	ComponentList compList;
	ComponentBitSet compBitset;
	std::vector<std::unique_ptr<Component>> components;  
};

#endif