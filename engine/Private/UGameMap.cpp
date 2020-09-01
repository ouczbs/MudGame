#include "..\Public\UGameMap.h"
#include "..\Public\Utility.h"
#include "..\Public\Const.h"
#include <sstream>
#include <iostream>

UGameMap::UGameMap(int _row, int _col)
{
	row = _row;
	col = _col;
	map = (int **)malloc(sizeof(int) *(_row));
	for (int i = 0; i < _row; ++i) {
		map[i] = new int[_col];
	};
}

bool UGameMap::checkMap(int x, int y)
{
	return x >= 0 && y >= 0 && x < row && y < col;
}

void UGameMap::addActor(UActorObject actor)
{
	actorList.push_back(actor);
	UVector pos = actor.getPos();
	if (!checkMap(pos.x, pos.y)) {
		return;
	};
	map[pos.x][pos.y] = actor.getId();
}

void UGameMap::removeActor(UActorObject actor)
{
	listRemove(actorList, actor);
	UVector pos = actor.getPos();
	if (!checkMap(pos.x, pos.y)) {
		return;
	};
	map[pos.x][pos.y] = 0;
}

void UGameMap::update()
{
	for (auto actor = actorList.begin(); actor != actorList.end();) {
		actor->update();
	}
}

void UGameMap::render()
{
	stringstream out , axis;
	out << parseName("", c_map_cell_size);
	for (int i = 0; i < row; ++i) {
		axis << "y" << i;
		out << c_map_color_head << parseName(axis.str(), c_map_cell_size) << c_map_color_tail;
		axis.str("");
	}
	for (int i = 0; i < row; ++i) {
		out << "\n";
		axis << "x" << i;
		out << c_map_color_head <<  parseName(axis.str() , c_map_cell_size) << c_map_color_tail;
		axis.str("");
		int * map_col = map[i];
		UActorObject * actor;
		for (int j = 0; j < col; ++j) {
			if (map_col[j] != 0 && (actor = searchActor(i, j) , actor != nullptr) ) {
				out << parseName( actor->getName() , c_map_cell_size);
			}
			else {
				out << parseName(c_map_cell, c_map_cell_size);
			};
		};
	};
	cout << out.str() << endl;
}

bool UGameMap::isEmpty(int x, int y)
{
	if (checkMap(x, y))
		return map[x][y] == 0;
	return false;
}

UActorObject * UGameMap::searchActor(int x, int y)
{
	for (auto actor = actorList.begin(); actor != actorList.end();) {
		UVector pos = actor->getPos();
		if (pos.x == x && pos.y == y) {
			return &*actor;
		}
	}
	return nullptr;
}
