#pragma once

#include "Csv.h"

class Quest {
public:
	int id = 0;
	int next = 0;
	int cond = 0;
	int npcid = 0;
	string text;
	vector<int> * choice = nullptr;
};
class QuestCsv : public Csv {
public:
	QuestCsv() {
		path = "./Csv/quest.csv";
	};

	map<int, Quest*>* makeAllQuestMap();
	map<int , Quest*>*  makeQuestMap();
};