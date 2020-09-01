#pragma once
#include<string>
using namespace std;
class UMessageManager {
private:
	string Message;
public:
	UMessageManager(){}
	void sendMessage(string message);
	void sendError(string message);
	void sendWarn(string message);
	void sendInfo(string message);
	string flush();
};