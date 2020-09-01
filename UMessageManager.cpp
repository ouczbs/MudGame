#include<string>
#include"UMessageManager.h"
using namespace std;
void UMessageManager::sendMessage(string message) {
	Message = Message + message;
}
void UMessageManager::sendError(string message) {
	Message = Message + "\033[31m" + message + "\033[0m";
}
void UMessageManager::sendWarn(string message) {
	Message = Message+"\033[33m" + message + "\033[0m";
}
void UMessageManager::sendInfo(string message) {
	Message = Message + "\033[34m" + message + "\033[0m";
}
string UMessageManager::flush() {
	string message;
	message = Message;
	Message = "";
	return message;
}