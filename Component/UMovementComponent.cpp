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
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x-=1;
	tempPos.y;
	//cout<< tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveBack(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x += 1;
	tempPos.y;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveLeft(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x;
	tempPos.y-=1;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveRight(string key, string cmd) {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x;
	tempPos.y+=1;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}