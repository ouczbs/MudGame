#pragma once
#include"../Engine/UComponent.h"
#include "../UWorld.h"
class UMovementComponent :public UComponent {
public:
	void init();

	void MoveForward(string , string );
	void MoveBack(string key, string cmd);
	void MoveLeft(string key, string cmd);
	void MoveRight(string key, string cmd);

};