
#include "UTalkManager.h"
#include "../UWorld.h"
#include "../Engine/Utility.h"
void TalkManager::visitNpc(int npcid)
{
	Quest* quest = findNpc(npcid);
	if (quest == nullptr)
		return;
	showTalking(quest);
}

void TalkManager::showTalking(Quest* quest)
{
	if (quest == nullptr)
		return;
	this->quest = quest;
	world->MessageManager->Info.appendLine(quest->text);
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

Quest* TalkManager::findNpc(int npcid)
{
	auto it = questMap->find(npcid);
	if (it != questMap->end()) {
		return it->second;
	}
	for (auto it = allQuestMap->begin(); it != allQuestMap->end(); it++) {
		if (it->second->npcid == npcid)
			return it->second;
	}
	return nullptr;
}
Quest* TalkManager::findQuest(int id)
{
	auto it = allQuestMap->find(id);
	if (it != allQuestMap->end()) {
		return it->second;
	}
	return nullptr;
}

void TalkManager::init()
{
	world->EventDispatcher->bindEvent("q" , this , &TalkManager::Talking);
}

void TalkManager::update()
{
	if (!this->quest)
		return;
	auto choice = this->quest->choice;
	if ( choice->size() > 0) {
		world->MessageManager->Tip.appendLine("输入 q + 数字选择 对话选项!");
	}
	else if(this->quest->next){
		world->MessageManager->Tip.appendLine("输入 q  进入下一条对话!");
	}

}

void TalkManager::Talking(string key, string cmd)
{
	if (!this->quest)
		return;
	auto choice = this->quest->choice;
	if (choice->size() == 0 && this->quest->next ) {
		Quest* quest = findQuest(this->quest->next);
		if (quest) {
			questMap->erase(quest->npcid);
			questMap->insert(pair<int, Quest*>(quest->npcid, quest));
		}
		return;
	}
	int id = safeStoi(cmd);
	
	if (id == 0 || choice->size() < id)
		return;
	Quest* quest = findQuest((*choice)[id - 1]);
	if (quest) {
		questMap->erase(quest->npcid);
		questMap->insert(pair<int, Quest*>(quest->npcid, quest));
	}
}

void TalkManager::clear()
{
	quest = nullptr;
}
