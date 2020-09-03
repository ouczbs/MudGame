#include "engine\UActorObject.h"
#include "Utility.h"

void UActorObject::addComponent(UComponent component) {
	component.setOwner(this);
	componentList.push_back(component);
};
void UActorObject::removeComponent(UComponent component) {
	component.setOwner(nullptr);
	/*int index;
	for (auto comp = componentList.begin(); comp != componentList.end();) {
		if (&*comp == &component) {
			comp.erase(componentList,component);
		}
	}*/
	listRemove(componentList, component);
};