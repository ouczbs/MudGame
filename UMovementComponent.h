#pragma once
#include"engine/UComponent.h"

class UMovementComponent :public UComponent {
public:
	void MoveForward();
	void MoveBack();
	void MoveLeft();
	void MoveRight();

};