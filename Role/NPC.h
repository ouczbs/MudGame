#pragma once
#include "role.h"
#include <string>
class NPC :public role {
public:
	void speaking();
	NPC() {
		id = 3;
	}
private:
	int id;
};