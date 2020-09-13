#pragma once
#include "System/UMessageManager.h"
#include "System/UIManager.h"
#include "System/UTalkManager.h"
#include "Engine/UGameMap.h"
#include "Engine/UEventDispatcher.h"
#include "Role/role.h"

class UWorld {
public:
	UMessageManager * MessageManager = nullptr;
	UIManager* UIManager = nullptr;
	TalkManager* TalkManager = nullptr;

	UEventDispatcher * EventDispatcher = nullptr;

	UGameMap * GameMap = nullptr;
	Role * Player = nullptr;

	string  nextGameMap = "";
	string gameMapName = "";
	string gameTitle = "";
	string uiName = "";

	bool Running = false;
	void render();
	void update();

	void run();

	map<string, IDelegate*> SceneMap;
	template<class T>
	T* findComponent(UActorObject * actor)
	{
		auto cls = T::StaticClass();
		auto componentList = actor->componentList;
		for (auto it = componentList->begin(); it != componentList->end(); it++) {
			auto name = (*it)->getClass();
			if (name  == cls) 
				return dynamic_cast<T*>(*it);
		}
		return nullptr;
	}

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