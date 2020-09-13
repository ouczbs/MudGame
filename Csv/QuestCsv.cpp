#include "QuestCsv.h"
#include "../Engine/Utility.h"
map<int, Quest*>* QuestCsv::makeAllQuestMap()
{
	map<int, Quest*>* res = new map<int, Quest*>();
	for (auto it = csv_data->begin(); it != csv_data->end(); it++) {
		Quest* quest = new Quest();
		auto vs = *(it->second);
		quest->id = it->first;
		int text_idx = getIndex("text");
		if(text_idx != -1)
			quest->text = vs[text_idx];
		int next_idx = getIndex("next");
		if (next_idx != -1)
			quest->next = safeStoi(vs[next_idx]);
		int choice_idx = getIndex("choice");
		if (choice_idx != -1) {
			quest->choice = conv(split(vs[choice_idx], ',') , true);
		}
		int npcid_idx = getIndex("npcid");
		if (npcid_idx != -1)
			quest->npcid = safeStoi(vs[npcid_idx]);
		int cond_idx = getIndex("cond");
		if (cond_idx != -1)
			quest->cond = safeStoi(vs[cond_idx]);

		res->insert(pair<int , Quest*>(quest->id , quest));
	}
	return res;
}

map<int, Quest*>* QuestCsv::makeQuestMap()
{
	return new map<int, Quest*>();
}
