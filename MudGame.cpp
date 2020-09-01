// MudGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Game/Public/UWorld.h"
int main()
{
	UWorld * world = new UWorld();
	world->MessageManager = new UMessageManager();
	world->MessageManager->Title.appendLine("欢迎进入游戏！！！");
	world->EventDispatcher = new UEventDispatcher();
	world->createMap("main", world->GameMap, world->Player);
	world->run();
}
