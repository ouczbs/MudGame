#pragma once
#include "UObject.h"
#include "UActorObject.h"
class UActorObject;
class UComponent : public UObject {

private:
	UActorObject * owner;
public:
	void setOwner(UActorObject * _owner);
	UActorObject * getOwner();

};