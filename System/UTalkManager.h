#pragma once
#include "../Csv/QuestCsv.h"
class TalkManager {
private:
	QuestCsv* questCsv = nullptr;
	map<int, Quest*>* allQuestMap = nullptr;
	map<int, Quest*>* questMap = nullptr;

	Quest* quest = nullptr;
public:
	TalkManager() {
		questCsv = new QuestCsv();
		questCsv->load();
		allQuestMap = questCsv->makeAllQuestMap();
		questMap = questCsv->makeQuestMap();
	};
	void visitNpc(int npcid);
	void showTalking(Quest * quest);
	Quest* findNpc(int npcid);
	Quest* findQuest(int id);

	void init();
	void update();
	void Talking(string key, string cmd);
};