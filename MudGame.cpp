// MudGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Engine/UActorObject.h"
#include "Engine/UGameMap.h"
#include "Role/player.h"
#include "Role/NPC.h"
#include "Role/monster.h"
#include "Component/UTalkComponent.h"
#include "Component/UMovementComponent.h"
#include "Component/UbagComponent.h"
#include "Component/UMeshComponent.h"

Weapon * addWeap(UGameMap* Map , int x , int y , string name , int id) {
	UActorObject* weap = new UActorObject();
	weap->setPos(x, y);
	UMeshComponent* meshComp = new UMeshComponent();
	weap->addComponent(meshComp);
	Weapon* thing = new Weapon();
	thing->setName(name);
	meshComp->setMesh(thing, id);
	Map->addActor(weap);
	return thing;
}
Heal* addHeal(UGameMap* Map, int x, int y, string name, int id) {
	UActorObject* heal = new UActorObject();
	heal->setPos(x, y);
	UMeshComponent* meshComp = new UMeshComponent();
	heal->addComponent(meshComp);
	Heal* thing = new Heal();
	thing->setName(name);
	meshComp->setMesh(thing, id);
	Map->addActor(heal);
	return thing;
}
Hero* addPlayer(UGameMap * Map ,int x , int y , string name , int id) {
	Hero* player = new Hero();
	player->setName(name);
	player->setPos(x, y);
	player->setId(id);
	UMovementComponent* playerMCom = new UMovementComponent();
	Bag* bag = new Bag();
	player->addComponent(playerMCom);
	player->addComponent(bag);
	Map->addActor(player);
	return player;
}
NPC* addNpc(UGameMap* Map, int x, int y, string name, int id) {
	NPC* npc = new NPC();
	npc->setName(name);
	npc->setPos(x, y);
	npc->setId(id);
	UTalkComponent* comp = new UTalkComponent();
	npc->addComponent(comp);
	Map->addActor(npc);
	return npc;
}
void makeMainScene(string key, string cmd) {
	UGameMap * Map = new UGameMap(10, 10);
	
	Hero* player = addPlayer(Map, 4, 4, "you", 1);
	addWeap(Map, 4, 4, "dagger", 1);
	addHeal(Map, 2, 1, "blood", 2);

	addNpc(Map, 7, 7, "npc1", 1);
	world->GameMap = Map;
	world->Player = player;
}
int main()
{

	world->EventDispatcher = new UEventDispatcher();
	world->MessageManager = new UMessageManager();
	world->TalkManager = new TalkManager();
	world->TalkManager->init();
	world->MessageManager->Title.appendLine("---------怪物猎人---------");
	world->MessageManager->Title.appendLine("新手村");
	world->MessageManager->Tip.appendLine("欢迎进入游戏！！！");

	world->addScene("main", makeMainScene);

	world->makeScene("main");

	world->update();
	world->run();
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
