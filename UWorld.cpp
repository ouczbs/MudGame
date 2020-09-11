#include "UWorld.h"
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
		makeScene(nextGameMap);
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


UWorld * world =new UWorld();