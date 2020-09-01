#pragma once
#include <string>
using namespace std;

class UObject {
private:
	string name;
	int id;

public:
	string getName() {
		return name;
	}
	int getId() {
		return id;
	};
};