#pragma once
#include <unordered_map>

class Settings
{
private:
	std::unordered_map<std::string, std::string> m_Items;
	char** m_Args;
	int m_Count;

public:
	Settings(char* args[], int count);
	std::string loadSettings();
	std::string getSetting(std::string name);
	bool hasSetting(std::string name);
};