#include "UEventDispatcher.h"
#include "Utility.h"

void UEventDispatcher::dispatcherEvent(string key, string cmd)
{
	auto it = delegateMap.find(key);
	if (it != delegateMap.end()) {
		(*(*it).second)(key, cmd);
	}
}

void UEventDispatcher::executeInput(string cmd)
{
	if (cmd.length() == 0)
		return;
	string key = cmd.substr(0, 1);
	dispatcherEvent(key, cmd);
}
