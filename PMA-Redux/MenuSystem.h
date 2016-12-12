#pragma once
#include <iostream>
#include <sstream>
class MenuSystem
{
public:
	MenuSystem();
	~MenuSystem();

	static void CommandLoadXMLFIle();
	static void CommandLoadMainMenu();
	static void CommandLoadDisplayData();
	static void CommandSortData();
	static void CommandSortTAs(bool order);
	static void CommmandAddTimeAllocation();
	static void CommandEditTimeAllocation();
	static void CommandAddProject();
	static void CommandAddTask();
};

