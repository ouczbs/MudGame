#pragma once
#include "UActorObject.h"
class UActorObject;
class UComponent {
private:
	UActorObject * owner;
public:
	virtual void setOwner(UActorObject* _owner);
	virtual void init();
	virtual UActorObject* getOwner();
};