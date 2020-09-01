#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include<list>
using namespace std;
class UComponent;
class UActorObject : public UObject {

private:
	list<UComponent> componentList;
	UVector pos;
public:
	UActorObject() {};
	UActorObject(int x , int y) {
		pos.x = x;
		pos.y = y;
	};
	void update() {

	};
	void addComponent(UComponent component) {
		component.setOwner(this);
		componentList.push_back(component);
	};
	void removeComponent(UComponent component) {
		component.setOwner(nullptr);
		componentList.remove(component);
	};
	UVector getPos() {
		return pos;
	};
};