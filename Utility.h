#pragma once
#include <string>
#include <sstream>
#include <list>   

using namespace std;

//string parseName(string name, int must_size);

template <class T>
inline bool listRemove(list<T> tList, T _t) {
	for (auto t = tList.begin(); t != tList.end();) {
		if (&*t == &_t) {
			tList.erase(t);
			return true;
		}
	};

	return false;
}
