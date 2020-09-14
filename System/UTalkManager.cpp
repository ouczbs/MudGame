
#include "UTalkManager.h"
#include "../UWorld.h"
#include "../Engine/Utility.h"
#include "../Engine/const.h"
UTalkManager::UTalkManager()
{
	questMap = world->CsvManager->questCsv->makeQuestMap();
}
void UTalkManager::visitNpc(int npcid)
{
	if (isShowAside && npcid != c_aside_id || !isShowAside && npcid == c_aside_id)
		return;
	Quest* quest = findNpc(npcid);
	if (quest == nullptr)
		return;
	showTalking(quest);
}

void UTalkManager::unVisitNpc(int npcid)
{
	if (quest && quest->npcid == npcid)
		quest = nullptr;
}

void UTalkManager::showTalking(Quest* quest)
{
	auto player = world->Player;
	if (!quest || !player)
		return;
	this->quest = quest;
	if(quest->before != "")
		world->MessageManager->Info.appendLine(player->displayName + ": "  + quest->before);
	world->MessageManager->Info.appendLine(quest->name + ": " + quest->text);
	auto choice = quest->choice;
	if (choice->size() == 0)
		return;
	int i = 0;
	for (auto it = choice->begin(); it != choice->end(); it++ ) {
		Quest* questChoice = findQuest(*it);
		if (questChoice != nullptr)
			world->MessageManager->Info.appendLine( to_string(++i) +". " + questChoice->text);
	}
}

Quest* UTalkManager::findNpc(int npcid)
{
	auto it = questMap->find(npcid);
	if (it != questMap->end()) {
		return it->second;
	}
	return world->CsvManager->findCQuestByNpcId(npcid);
}
Quest* UTalkManager::findQuest(int id)
{
	return world->CsvManager->findCQuest(id);
}

void UTalkManager::init()
{
	world->EventDispatcher->bindEvent("q" , this , &UTalkManager::Talking);
}

void UTalkManager::update()
{
	if (questMap->size() > 0) {
		for (auto it = questMap->begin(); it != questMap->end(); it++) {
			Quest * _quest = it->second;
			if (_quest->npcid != c_aside_id) {
				CRole* cr = world->CsvManager->findCRole(_quest->npcid);
				if(cr)
					world->MessageManager->Tip.appendLine(cr->showname + " : " + cr->name + " , id = " + to_string(cr->id) + " 可交互 ");
			}
		}
	}
	if (!this->quest)
		return;
	auto choice = this->quest->choice;
	if ( choice->size() > 0) {
		world->MessageManager->Tip.appendLine("输入 q + 数字选择 对话选项!");
	}
	else if(this->quest->next){
		Quest* nextQuest = findQuest(this->quest->next);
		if(nextQuest != nullptr && nextQuest->npcid == this->quest->npcid)
			world->MessageManager->Tip.appendLine("输入 q  进入下一条对话!");
	}

}

void UTalkManager::Talking(string key, string cmd)
{
	auto player = world->Player;
	if (!this->quest || !player)
		return;
	Quest* quest = this->quest;
	if (quest->after != "")
		world->MessageManager->Info.appendLine(player->displayName + ": " + quest->after);
	auto choice = this->quest->choice;
	if (choice->size() == 0 && this->quest->next ) {
		Quest* nextQuest = findQuest(this->quest->next);
		nextTalking(nextQuest);
		return;
	}
	int id = safeStoi(cmd) - 1;
	if (id < 0 || choice->size() <= id)
		return;
	Quest* nextQuest = findQuest((*choice)[id]);
	if(nextQuest)
		nextTalking(findQuest(nextQuest->next));
}

void UTalkManager::nextTalking(Quest* _quest)
{
	if (_quest) {
		if ( _quest->npcid == c_aside_id) {
			isShowAside = true;
		}
		else {
			isShowAside = false;
		}
		questMap->erase(_quest->npcid);
		questMap->insert(pair<int, Quest*>(_quest->npcid, _quest));
	}
}

void UTalkManager::clear()
{
	quest = nullptr;
}
