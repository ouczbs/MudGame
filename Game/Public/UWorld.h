#pragma once
#include "UMessageManager.h"
#include "UPlayer.h"
#include "../../Engine/Public/UGameMap.h"
#include "../../Engine/Public/UEventDispatcher.h"

static class UWorld {
public:
	UMessageManager * MessageManager;
	UEventDispatcher * EventDispatcher;

	UGameMap * GameMap;
	UPlayer * Player;

	string  nextGameMap = "";

	bool Running;
	void render();
	void update();

	void run();
	bool createMap(string map, UGameMap * gameMap, UPlayer * player);
};