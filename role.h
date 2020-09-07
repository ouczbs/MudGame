#pragma once
#include"engine/UActorObject.h"
class role:public UActorObject {
public:
	/*role(int nattack_value, int ndefence_value, int nblood_value) {
		attack_value = nattack_value;
		defence_value = ndefence_value;
		blood_value = nblood_value;
	}*/
private:
	int attack_value;
	int defence_value;
	int blood_value;
};

