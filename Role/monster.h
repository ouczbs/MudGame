#pragma once
#include"role.h"

class monster :public Role {
public:
	monster() {
		id = 2;
	}
private:
	int id;
};
