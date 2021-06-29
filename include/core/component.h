#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;
#include <vector>

class Component {
public:
	Entity* owner;
	virtual ~Component(){}
	virtual void init (){}
	virtual void update(){float dt}
	virtual void render(){}
private:
	//nothing
};

#endif