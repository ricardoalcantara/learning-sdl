#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
	Component{} = default;
	virtual ~Component{} = default;

	Entity* entity;

	virtual bool init() { return true; }
	virtual void draw() {}
	virtual void update(){}
private:
};

#endif