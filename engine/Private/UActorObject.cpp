#include "..\Public\UActorObject.h"
#include "..\Public\Utility.h"
UActorObject::UActorObject()
{
}
UActorObject::UActorObject(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

UVector UActorObject::getPos()
{
	return pos;
}


void UActorObject::update()
{
}

void UActorObject::addComponent(UComponent component)
{
	component.setOwner(this);
	componentList.push_back(component);
}

void UActorObject::removeComponent(UComponent component)
{
	listRemove(componentList, component);
	component.setOwner(nullptr);
}
