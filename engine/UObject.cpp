#include "UObject.h"

string UObject::getName()
{
	return name;
}

UObject::UObject(string name, int id)
{
}

UObject::UObject()
{
}

void UObject::setName(string _name)
{
	name = _name;
}

int UObject::getId()
{
	return id;
}

void UObject::setId(int _id)
{
	id = _id;
}
