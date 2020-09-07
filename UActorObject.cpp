#include "engine\UActorObject.h"
#include "Utility.h"

void UActorObject::addComponent(UComponent &component) {
	component.setOwner(this);
	componentList.push_back(component);
};
void UActorObject::removeComponent(UComponent component) {
	component.setOwner(nullptr);
	listRemove(componentList, component);
};