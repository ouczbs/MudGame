#pragma once
#include "UActorObject.h"
class UActorObject;
class UComponent {
private:
	UActorObject * owner;
public:
	UComponent() {
		;
	}
	void setOwner(UActorObject *_owner) {
		owner = _owner;
	}
	UActorObject *getOwner() {
		return owner;
	}
};