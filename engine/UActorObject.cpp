#include "UActorObject.h"
#include "Utility.h"

void UActorObject::addComponent(UComponent * component) {
	component->setOwner(this);
	component->init();
	componentList.push_back(component);
};
void UActorObject::removeComponent(UComponent *component) {
	component->setOwner(nullptr);
	listRemove(componentList, component);
};