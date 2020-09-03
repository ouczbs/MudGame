#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include <list>
#include <string>

using namespace std;

string parseName(string name, int cell) {
	int size = name.length();
	if (size == cell)
		return name;
	string res = "";
	if (size < cell) {
		for (int i = size; i < cell; i++)
			res.append("");
		res.append(name);
	}
	else {
		for (int i = 0; i < cell; i++)
			res[i]==name[i];
	}
	return res;
};
class UGameMap {
private:
	int** map;
	int row;
	int col;
	list<UActorObject> actorList;

public:
	UGameMap(int x, int y) {
		map =  (int**)malloc(sizeof(int*) * x);
		for (int i = 0; i < x; i++)
			map[i] = (int*)malloc(sizeof(int) * y);
		row = x; 
		col = y;
	};
	bool checkMap(int x, int y) {
		return x >= 0 && y >= 0 && x < row&& y < col;
	};
	void update() {
		for (auto actor = actorList.begin(); actor != actorList.end();) {
			actor->update();
		}
	};
	void addActor(UActorObject actor) {
		actorList.push_back(actor);
		UVector pos = actor.getPos();
		if (!checkMap(pos.x, pos.y))
			return;
		map[pos.x][pos.y] = actor.getId();
	};
	void removeActor(UActorObject actor) {
		//actorList.remove(actor);
		UVector pos = actor.getPos();
		if (!checkMap(pos.x, pos.y))
			return;
		map[pos.x][pos.y] = 0;
	};
	UActorObject* searchActor(int x , int y) {
		for (auto actor = actorList.begin(); actor != actorList.end();) {
			UVector pos = actor->getPos();
			if (pos.x == x && pos.y == y)
				return &*actor;
		}
	}
	bool isEmpty( int x , int y) {
		if (!checkMap(x, y))
			return false;
		return map[x][y] == 0;
	}
	void render() {

	}

};