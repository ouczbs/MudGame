#include "..\Public\Utility.h"
string parseName(string name, int must_size) {
	int size = int(name.length());
	if (size == must_size) {
		return name;
	}
	stringstream ss;
	if (size < must_size) {
		for (int i = size; i < must_size; i++)
			ss << " ";
		ss << name;
	}
	else {
		for (int i = 0; i < size; i++)
			ss << name[i];
	}
	string res = ss.str();
	ss.str("");
	return res;
}
