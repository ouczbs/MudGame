#pragma once
#include "System/UMessageManager.h"
#include "Role/UPlayer.h"
#include "Engine/UGameMap.h"
#include "Engine/UEventDispatcher.h"

class UWorld {
public:
	UMessageManager * MessageManager = nullptr;
	UEventDispatcher * EventDispatcher = nullptr;

	UGameMap * GameMap = nullptr;
	UPlayer * Player = nullptr;

	string  nextGameMap = "";

	bool Running = false;
	void render();
	void update();

	void run();
	bool createMap(string map, UGameMap * gameMap, UPlayer * player);
};

UWorld world;