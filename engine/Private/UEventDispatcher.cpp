#include "..\Public\UEventDispatcher.h"
#include "..\Public\Utility.h"
void UEventDispatcher::bindEvent(string key, EventHandle handle)
{
	auto it =  delegateMap.find(key);
	if (it == delegateMap.end()) {
		// 没找到 ，创建一个新委托
		list<EventHandle> delegate;
		delegate.push_back(handle);
		delegateMap.insert(pair<string, EventDelegate>(key, delegate));
	}
	else {
		it->second.push_back(handle);
	}
}

void UEventDispatcher::unBindEvent(string key, EventHandle handle)
{
	auto it = delegateMap.find(key);
	if (it != delegateMap.end()) {
		listRemove(it->second, handle);
	}
}

void UEventDispatcher::dispatcherEvent(string key, string cmd)
{
	auto it = delegateMap.find(key);
	if (it != delegateMap.end()) {
		auto delegate = it->second;
		for (auto it = delegate.begin(); it != delegate.end();) {
			EventHandle handle = *it;
			handle(key , cmd);
		}
	}
}

void UEventDispatcher::executeInput(string cmd)
{
	if (cmd.length() == 0)
		return;
	string key = string(cmd , 1);
	dispatcherEvent(key , cmd);
}
