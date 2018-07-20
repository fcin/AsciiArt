#include "Settings.h"
#include<iostream>

Settings::Settings(char* args[], int count) : m_Args(args), m_Count(count)
{
	
}

std::string Settings::loadSettings()
{
	if (m_Count <= 0)
		return "";

	m_Items.insert({ "basePath", m_Args[0] });

	if (m_Count == 1)
		return "";

	if (m_Count % 2 == 0)
		return "Some arguments are missing parameters";

	for (int index = 1; index < m_Count; index += 2)
	{
		std::string currArgument(m_Args[index]);
		std::string currValue(m_Args[index + 1]);

		if (currArgument.compare("-src") == 0)
		{
			m_Items.insert({ "src", currValue.c_str() });
		}
		else if (currArgument.compare("-out") == 0)
		{
			m_Items.insert({ "out", currValue.c_str() });
		}
	}

	return "";
}

std::string Settings::getSetting(std::string name)
{
	if (m_Items.find(name) != m_Items.end())
		return m_Items[name];

	return "";
}

bool Settings::hasSetting(std::string name)
{
	return m_Items.find(name) != m_Items.end();
}