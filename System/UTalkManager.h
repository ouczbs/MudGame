#pragma once
#include "../Csv/QuestCsv.h"
#include "../Csv/RoleCsv.h"
class UTalkManager {
private:
	map<int, Quest*>* questMap = nullptr;
	Quest* quest = nullptr;

	bool isShowAside = true;

public:
	UTalkManager();
	void visitNpc(int npcid);
	void unVisitNpc(int npcid);
	void showTalking(Quest * quest);
	Quest* findNpc(int npcid);
	Quest* findQuest(int id);

	void init();
	void update();
	void Talking(string key, string cmd);
	void nextTalking(Quest * _quest);
	void clear();
};