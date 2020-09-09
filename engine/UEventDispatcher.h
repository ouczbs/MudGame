#pragma once
#include <string>
#include<functional>
#include <list>
#include <map> 
using namespace std;

typedef function<void(string , string)> EventHandle;
typedef list<EventHandle> EventDelegate;

class UEventDispatcher {

private:
	map<string, EventDelegate> delegateMap;

public:
	void bindEvent(string key, EventHandle handle);
	void unBindEvent(string key, EventHandle handle);
	void dispatcherEvent(string key , string cmd);

	void executeInput(string cmd);
};
