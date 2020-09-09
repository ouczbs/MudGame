// MudGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Engine/UActorObject.h"
#include "Engine/UGameMap.h"
#include "Role/player.h"
#include "Component/UMovementComponent.h"
/*
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
*/
int main()
{
	UGameMap Map(10, 10);
	//UObject player("songzetao", 1);
	Hero player;
	player.setName("songzetao");
	player.setPos(2, 3);
	player.setId(1);
	Map.addActor(&player);
	Map.render();
	UMovementComponent playerMCom;
	player.addComponent(playerMCom);
	cout << endl;
	while (1) {
		char key;
		cin >> key;
		if (key == 'w') {
			playerMCom.MoveForward();
			Map.update();
			Map.render();
		}
		else if (key == 's') {
			playerMCom.MoveBack();
			Map.update();
			Map.render();
		}
		else if (key == 'a') {
			playerMCom.MoveLeft();
			Map.update();
			Map.render();
		}
		else if (key == 'd') {
			playerMCom.MoveRight();
			Map.update();
			Map.render();
		}
		else {
			cout << "输入错误，请重新输入！";
		}
			
	}
	//playerMCom.MoveRight();
	//cout << player.getPos().x << player.getPos().y << endl;
	
	//getchar();
}
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
//
// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
