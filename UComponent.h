#pragma once
#include "UActorObject.h"
class UActorObject;
class UComponent {
private:
	UActorObject * owner;
public:
	void setOwner(UActorObject *_owner) {
		owner = _owner;
	}
};