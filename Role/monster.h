#pragma once
#include"role.h"

class monster :public role {
public:
	monster() {
		id = 2;
	}
private:
	int id;
};
