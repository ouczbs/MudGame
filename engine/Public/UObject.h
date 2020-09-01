#pragma once
#include <string>
using namespace std;

class UObject {

private:
	string name;
	int id;

public:
	string getName();
	void setName(string _name);
	int getId();
	void setId(int _id);

};