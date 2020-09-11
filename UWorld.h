#pragma once
#include "System/UMessageManager.h"
#include "Engine/UGameMap.h"
#include "Engine/UEventDispatcher.h"
#include "Role/role.h"

class UWorld {
public:
	UMessageManager * MessageManager = nullptr;
	UEventDispatcher * EventDispatcher = nullptr;

	UGameMap * GameMap = nullptr;
	Role * Player = nullptr;

	string  nextGameMap = "";

	bool Running = false;
	void render();
	void update();

	void run();

	map<string, IDelegate*> SceneMap;

	template<class T>
	void addScene(string key, T* _object, void (T::* _method)(string, string)) {
		auto it = SceneMap.find(key);
		if (it == SceneMap.end()) {
			IDelegate* handle = newDelegate(_object, _method);
			SceneMap.insert(pair<string, IDelegate*>(key, handle));
		}
	}
	void addScene(string key, void (*_func)(string, string)) {
		auto it = SceneMap.find(key);
		if (it == SceneMap.end()) {
			IDelegate* handle = newDelegate(_func);
			SceneMap.insert(pair<string, IDelegate*>(key, handle));
		}
	}
	void makeScene(string key) {
		auto it = SceneMap.find(key);
		if (it != SceneMap.end()) {
			(*it).second ->invoke("" , "");
		}
	}
};

extern UWorld * world;