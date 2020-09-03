#pragma once
#include <string>
using namespace std;

class UObject {
private:
	string name;
	int id;

public:
	UObject(string name, int id) {
		this->name = name;
		this->id = id;
	}

	UObject() {

	}

	void setName(string name) {
		this->name = name;
	}
	void setId(int id) {
		this->id = id;
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	};
};