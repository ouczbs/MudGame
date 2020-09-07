#include"UMovementComponent.h"
#include<iostream>
using namespace std;

void UMovementComponent::MoveForward() {
	UVector tempPos;
	tempPos=this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x-=1;
	tempPos.y;
	//cout<< tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveBack() {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x += 1;
	tempPos.y;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveLeft() {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x;
	tempPos.y-=1;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}

void UMovementComponent::MoveRight() {
	UVector tempPos;
	tempPos = this->getOwner()->getPos();
	//cout << tempPos.x << tempPos.y << endl;
	tempPos.x;
	tempPos.y+=1;
	//cout << tempPos.x << tempPos.y << endl;
	this->getOwner()->setPos(tempPos.x, tempPos.y);
}