#pragma once
class MenuSystem
{
public:
	MenuSystem();
	~MenuSystem();

	static void CommandLoadXMLFIle();
	static void CommandLoadMainMenu();
	static void CommandLoadDisplayData();
	static void CommandSortData();
	static void CommandSortTAs(bool order); //0 for assending, 1 for desending
	static void CommmandAddTimeAllocation();
	static void CommandEditTimeAllocation();
};

