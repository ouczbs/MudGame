
#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include <list>   
using namespace std;
class UComponent;
class UActorObject : public UObject {

private:
	int id = 1;
	UVector pos;
	list<UComponent> componentList;
public:
	UActorObject();
	UActorObject(int x, int y);
	UVector getPos();
	void update();
	void addComponent(UComponent component);
	void removeComponent(UComponent component);
};