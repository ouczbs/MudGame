#include "..\Public\UWorld.h"
#include <iostream>   
using namespace std;
void UWorld::render()
{
	if (GameMap != nullptr) {
		GameMap->render();
	}
}

void UWorld::update()
{
	if (nextGameMap != "") {
		createMap(nextGameMap, GameMap, Player);
		nextGameMap = "";
	}
	if (GameMap != nullptr) {
		GameMap->update();
	}
}

void UWorld::run()
{
	Running = true;
	while (Running) {
		MessageManager->showTitle();
		MessageManager->showTip();
		render();
		string cmd; cin >> cmd;
		EventDispatcher->executeInput(cmd);
		update();
		MessageManager->showInfo();
		MessageManager->showError();
	}
}

bool UWorld::createMap(string map, UGameMap * gameMap, UPlayer * player)
{
	//"..."

	return false;
}
