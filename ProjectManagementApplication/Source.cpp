#include "DataCzar.h"
#include "Utils.h"
#include <algorithm>

void CommandLoadXMLFIle();
void CommandLoadMainMenu();
void CommandLoadDisplayData();
void CommandSortData();
void CommandSortTAs(bool order); //0 for assending, 1 for desending
void CommandSelectProjectAndEdit();
void CommandSelectTask(Project * pP);
void CommandAddTA(Task * pT);

//commands to sort data
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
		case 'Y':
			CommandSortTAs(true);
			success = true;
			break;
		case 'n':
		case 'N':
			CommandSortTAs(false);
			success = true;
			break;
		default:
			std::cout << "That command is no recognised, please try again.\n";
			break;
		}
	}

	CommandLoadMainMenu();
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
				std::sort(t.GetTAs().begin(), t.GetTAs().end(), Utils::IsGreaterThan);

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
		std::vector<std::shared_ptr<TimeAllocation>> master;
		//add all TAs in entire dataczar
		for (Project &p : DataCzar::Current->GetProjects())
		{
			for (Task &t : p.GetTasks())
			{
				master.insert(master.end(), t.GetTAs().begin(), t.GetTAs().end());
			}
		}

		std::sort(master.begin(), master.end(), Utils::IsGreaterThan);

		if (response == 1)
		{
			//reverse the vector
			std::reverse(master.begin(), master.end());
		}

		RuntimeMenu::DisplayTitle();

		//then print them all
		for (std::shared_ptr<TimeAllocation> ta : master)
		{
			std::cout << ta << "\n";
		}

		std::cin.get();
		std::cin.get();
	}

	
}

//command to load xml
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

//command to display loaded xml data
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

	CommandLoadMainMenu();
}

//commands to select project and add a time allocation to a subtask
void CommandSelectProjectAndEdit()
{
	RuntimeMenu::DisplayTitle();

	std::cout << "Here are the currently loaded projects:\n";

	for (Project &p : DataCzar::Current->GetProjects())
	{
		std::cout << p.GetName() << "\n";
	}

	std::cout << "Enter the name of the project you wish to edit:\n";

	std::string input;
	bool success = false;
	Project * projectToEdit = nullptr;

	while (!success)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, input);

		for (Project &p : DataCzar::Current->GetProjects())
		{
			if (p.GetName() == input)
			{
				success = true;
				projectToEdit = &p;
			}
		}

		if (!success)
		{
			std::cout << "Project not recognised, please try again. \n";
		}
	}

	CommandSelectTask(projectToEdit);
}

void CommandSelectTask(Project * pP)
{
	RuntimeMenu::DisplayTitle();

	std::cout << "Here are the currently loaded tasks:\n";

	for (Task &t : pP->GetTasks())
	{
		std::cout << t.GetName() << "\n";
	}

	std::cout << "Enter the name of the task you wish to edit:\n";

	std::string input;
	bool success = false;
	Task * taskToEdit = nullptr;

	while (!success)
	{
		std::getline(std::cin, input);

		for (Task &t : pP->GetTasks())
		{
			if (t.GetName() == input)
			{
				success = true;
				taskToEdit = &t;
			}
		}
		if (!success)
		{
			std::cout << "Task not recognised, please try again. \n";
		}
	}

	CommandAddTA(taskToEdit);
}

void CommandAddTA(Task * pT)
{
	RuntimeMenu::DisplayTitle();

	std::cout << "What kind of Time Allocation would you like to add? \n";
	std::cout << "1. Meeting\n";
	std::cout << "2. Work Done\n";
	std::cout << "3. Bug Fix\n";
	std::cout << "4. Research\n";

	int input = 0;
	bool success = false;
	while (!success)
	{
		std::cin >> input;

		switch (input)
		{
		case 1:
			success = true;
			//meeting
			Utils::CreateMeeting(pT);
			break;
		case 2:
			success = true;
			//work done
			Utils::CreateWorkDone(pT);
			break;
		case 3:
			success = true;
			//bug fix
			Utils::CreateBugFix(pT);
			break;
		case 4:
			success = true;
			//research
			Utils::CreateResearch(pT);
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}

	//write to file
	//pain
	DataCzar::Current->SaveToFile();

	std::cout << "Time Allocation added. Press any key to continue";
	std::cin.get();

	CommandLoadMainMenu();
}

//command to load the main menu
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
			CommandSelectProjectAndEdit();
			break;
		case 5:
			responseSuccess = true;
			return;
			//quit
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}
}


//main
int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);

	//DataCzar Data("testing.xml");
	//DataDisplayer::PrintTest(Data);

	//initialise static dataczar
	std::shared_ptr<DataCzar> d(new DataCzar);
	DataCzar::Current = d;

	CommandLoadMainMenu();
}