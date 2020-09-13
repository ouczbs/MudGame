#include"UMovementComponent.h"
#include<iostream>
#include<functional>
#include "../Engine/Delegate.h"
using namespace std;

void UMovementComponent::init()
{
	world->EventDispatcher->bindEvent("w" ,this, &UMovementComponent::MoveForward);
	world->EventDispatcher->bindEvent("s", this, &UMovementComponent::MoveBack);
	world->EventDispatcher->bindEvent("a", this, &UMovementComponent::MoveLeft);
	world->EventDispatcher->bindEvent("d", this, &UMovementComponent::MoveRight);

}
void UMovementComponent::MoveForward(string key , string cmd) {
	UVector tempPos;
	tempPos= this->getOwner()->getPos();
	tempPos.x-=1;
	tempPos.y;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围，无法移动");
}

void UMovementComponent::MoveBack(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	tempPos.x += 1;
	tempPos.y;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围，无法移动");
}

void UMovementComponent::MoveLeft(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	tempPos.x;
	tempPos.y-=1;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围，无法移动");
}

void UMovementComponent::MoveRight(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	tempPos.x;
	tempPos.y+=1;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围，无法移动");
}

void UMovementComponent::update()
{
	world->MessageManager->Tip.appendLine("请输入 w a s d 移动, 后加数字可移动多个单位");
}
