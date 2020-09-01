#pragma once
#include "UActorObject.h"
#include <string>
#include <list>   
using namespace std;


class UGameMap {

private:
	int ** map;
	int row;
	int col;

	list<UActorObject> actorList;
public:
	UGameMap(int _row, int _col);
	bool checkMap(int x, int y);
	void addActor(UActorObject actor);
	void removeActor(UActorObject actor);
	void update();
	void render();
	bool isEmpty(int x, int y);
	UActorObject * searchActor(int x, int y);

};