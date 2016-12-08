#include <iostream>
#include "DataCzar.h"
#include "DataDisplayer.h"
#include "RuntimeMenu.h"
#include <algorithm>
#include "TimeAllocation.h"

void CommandLoadXMLFIle();
void CommandLoadMainMenu();
void CommandLoadDisplayData();
void CommandDisplayTAsOnly();
void CommandSortData();
void CommandSortTAs(bool order); //0 for assending, 1 for desending

void CommandSortData()
{
	RuntimeMenu::DisplayTitle();

	std::cout << "Would you like to see the Time Allocations grouped with appropriate tasks and projects? Y/N\n";
	bool success = false;
	char response;
	while (!success)
	{
		std::cin >> response;

		switch (response)
		{
		case 'y':
			//CommandLoadDisplayData();
			CommandSortTAs(true);
			break;
		case 'n':
			CommandSortTAs(false);
			//CommandDisplayTAsOnly();
			break;
		default:
			std::cout << "That command is no recognised, please try again.\n";
			break;
		}
	}
}

const bool IsGreaterThan(TimeAllocation* lhs, TimeAllocation* rhs)
{
	return (*lhs) < (*rhs);
}

void CommandSortTAs(bool full) //true for assending, false for desending
{
	std::cout << "Before displaying the data, how would you like it sorted?\n";
	std::cout << "1. Assending\n";
	std::cout << "2. Desending\n";

	int response;
	bool responseSuccess = false;
	while (!responseSuccess)
	{
		std::cin >> response;

		switch (response)
		{
		case 1:
			responseSuccess = true;
			//assending
			break;
		case 2:
			responseSuccess = true;
			//desending
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}

	if (full)
	{
		for (Project &p : DataCzar::Current->GetProjects())
		{
			for (Task &t : p.GetTasks())
			{
				std::sort(t.GetTAs().begin(), t.GetTAs().end(), IsGreaterThan);

				if (response == 1)
				{
					//reverse the vector
					std::reverse(t.GetTAs().begin(), t.GetTAs().end());
				}
			}
		}

		CommandLoadDisplayData();
	}
	else
	{
		std::vector<TimeAllocation*> master;
		//add all TAs in entire dataczar
		for (Project &p : DataCzar::Current->GetProjects())
		{
			for (Task &t : p.GetTasks())
			{
				master.insert(master.end(), t.GetTAs().begin(), t.GetTAs().end());
			}
		}

		std::sort(master.begin(), master.end(), IsGreaterThan);

		if (response == 1)
		{
			//reverse the vector
			std::reverse(master.begin(), master.end());
		}

		//then print them all
		for (TimeAllocation* ta : master)
		{
			std::cout << ta << "\n";
		}

		std::cin.get();
		std::cin.get();
	}

	
}

void CommandDisplayTAsOnly()
{
	
}

void CommandLoadXMLFIle()
{
	RuntimeMenu::DisplayLoadXMLMenu();
	std::string inputPath;
	bool success = false;
	while (!success)
	{
		std::cin >> inputPath;
		tinyxml2::XMLError error = DataCzar::Current->SetUp(inputPath);
		if (error == tinyxml2::XML_SUCCESS)
		{
			std::cout << "Data loaded successfully. Press any key to continue...";
			success = true;
		}
		else
		{
			std::cout << "ERROR: " << error << "\n";
			std::cout << "Loading failed. The file may not exist or be mispelled. Please try again:\n";
		}
	}
	std::cin.get();
	std::cin.get();
	CommandLoadMainMenu();
}

void CommandLoadDisplayData()
{
	const int count = DataCzar::Current->GetProjects().size();
	int current = 1;
	for (Project p : DataCzar::Current->GetProjects())
	{
		RuntimeMenu::DisplayTitle();
		std::cout << "Project " << current++ << " of " << count << "\n";
		std::cout << p;
		std::cin.get();
		std::cin.get();
	}
}

void CommandLoadMainMenu()
{
	int response;
	bool responseSuccess = false;
	RuntimeMenu::DisplayMainMenu();

	while (!responseSuccess)
	{
		std::cin >> response;

		switch (response)
		{
		case 1:
			responseSuccess = true;
			//load xml file
			CommandLoadXMLFIle();
			break;
		case 2:
			responseSuccess = true;
			//display data
			CommandLoadDisplayData();
			break;
		case 3:
			responseSuccess = true;
			//sort data, then display
			CommandSortData();
			break;
		case 4:
			responseSuccess = true;
			//edit data
			break;
		case 5:
			responseSuccess = true;
			//quit
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);

	//DataCzar Data("testing.xml");
	//DataDisplayer::PrintTest(Data);

	DataCzar::Current = new DataCzar();

	CommandLoadMainMenu();
	
	std::cin.get();
	std::cin.get();
}