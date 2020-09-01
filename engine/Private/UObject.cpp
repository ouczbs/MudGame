#include "..\Public\UObject.h"

string UObject::getName()
{
	return name;
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
