#include "..\Public\UComponent.h"

void UComponent::setOwner(UActorObject * _owner)
{
	owner = _owner;
}

UActorObject * UComponent::getOwner()
{
	return owner;
}
