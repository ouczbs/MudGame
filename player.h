#pragma once
#include"role.h"

class Hero :public role {
public:
	Hero() {
		id = 1;
	}
private:
	int gold_value;
	int id;
	//Thing bag[10];
	//Weapon equipment[2];
};