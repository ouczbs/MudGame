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
		GameMap->destroy();
		TalkManager->clear();
		makeScene(nextGameMap);
		nextGameMap = "";
	}
	world->MessageManager->Title.appendLine(gameTitle);
	world->MessageManager->Title.appendLine(gameMapName);
	if (GameMap != nullptr) {
		GameMap->update();
	}
	if (TalkManager != nullptr) {
		TalkManager->update();
	}
}

void UWorld::run()
{
	Running = true;
	while (Running) {
		system("cls");
		MessageManager->show();
		render();
		string cmd; cin >> cmd;
		EventDispatcher->executeInput(uiName , cmd);
		update();
	}
}


UWorld * world =new UWorld();