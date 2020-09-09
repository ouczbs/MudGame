#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include <list>
#include <string>

using namespace std;

class UGameMap {
private:
	int** map;
	int row;
	int col;
	list<UActorObject *> actorList;
public:
	UGameMap(int _row, int _col);
	bool checkMap(int x, int y);
	void update();
	void addActor(UActorObject* actor);
	UActorObject * searchActor(int x, int y);
	void removeActor(UActorObject actor);
	bool isEmpty(int x, int y);
	void render();

};