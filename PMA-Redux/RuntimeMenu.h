#pragma once
#include <iostream>
#include <sstream>
class RuntimeMenu
{
public:
	RuntimeMenu();
	~RuntimeMenu();

	static void DisplayMainMenu();
	static void DisplayLoadXMLMenu();
	static void DisplayTitle();
	static std::string TurnIntoSubtitle(std::string s, std::string spacer);
	static std::string GetTimeSpentString(int minutesSpent, std::string spacer);
};

