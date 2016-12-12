#include "MenuSystem.h"
#include "RuntimeMenu.h"
#include "DataCzar.h"
#include "Utils.h"
#include <algorithm>
#include <functional>
#include <memory>

MenuSystem::MenuSystem(){}
MenuSystem::~MenuSystem(){}

//void CommandSelectTask(Project * pP);
void CommandAddTA(Task * pT);
//void CommandEditSelectedTA(std::shared_ptr<TimeAllocation> &pTa);
Project * GetProjectSelectionFromUser();
Task * GetTaskSelectionFromUser(Project * projectToEdit);
std::shared_ptr<TimeAllocation> GetTimeAllocationSelectionFromUser(Task * taskToEdit);

//command to load the main menu
void MenuSystem::CommandLoadMainMenu()
{
	int response = 0;
	while (response != 9)
	{
		RuntimeMenu::DisplayMainMenu();
		std::cin >> response;

		switch (response)
		{
		case 1:
			//load xml file
			CommandLoadXMLFIle();
			break;
		case 2:
			//display data
			CommandLoadDisplayData();
			break;
		case 3:
			//sort data, then display
			CommandSortData();
			break;
		case 4:
			//add ta
			CommmandAddTimeAllocation();
			break;
		case 5:
			//add task
			CommandAddTask();
			break;
		case 6:
			//add proj
			CommandAddProject();
			break;
		case 7:
			//edit ta
			CommandEditTimeAllocation();
			break;
		case 9:
			return;
			//quit
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}
}

//command to load xml
void MenuSystem::CommandLoadXMLFIle()
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
			if (inputPath == "#")
			{
				return;
			}
			else
			{
				std::cout << "ERROR: " << error << "\n";
				std::cout << "Loading failed. The file may not exist or be mispelled. Please try again:\n";
			}
		}
	}
	Utils::Pause();
	//CommandLoadMainMenu();
}

//command to display loaded xml data
void MenuSystem::CommandLoadDisplayData()
{
	const int count = DataCzar::Current->GetProjects().size();
	if (count <= 0)
	{
		//no data loaded
		//return to menu
		RuntimeMenu::DisplayTitle();
		std::cout << "Sorry, you have not loaded any data, or no Projects were found in the data. Try loading another file.";
		Utils::Pause();
	}
	else
	{
		int current = 1;
		for (Project p : DataCzar::Current->GetProjects())
		{
			RuntimeMenu::DisplayTitle();
			std::cout << "Project " << current++ << " of " << count << "\n";
			std::cout << p;
			Utils::Pause();
		}
	}
}

//commands to sort data
void MenuSystem::CommandSortData()
{
	RuntimeMenu::DisplayTitle();

	std::cout << "Would you like to see the Time Allocations grouped with appropriate tasks and projects? Y/N\n(Use # to return to main menu)\n";
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
		case '#':
			return;
		default:
			std::cout << "That command is no recognised, please try again.\n";
			break;
		}
	}

	//CommandLoadMainMenu();
}

void MenuSystem::CommandSortTAs(bool full) //true for assending, false for desending
{
	std::cout << "Before displaying the data, how would you like it sorted?\n";
	std::cout << "(Enter # to return to the main menu)\n";
	std::cout << "1. Desending\n";
	std::cout << "2. Assending\n";

	char response;
	bool responseSuccess = false;
	while (!responseSuccess)
	{
		std::cin >> response;

		switch (response)
		{
		case '1':
		case '2':
			responseSuccess = true;
			break;
		case '#':
			return;
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
				std::sort(t.GetTAs().begin(), t.GetTAs().end(), std::greater<std::shared_ptr<TimeAllocation>>());

				if (response == '1')
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

		std::sort(master.begin(), master.end(), std::greater<std::shared_ptr<TimeAllocation>>());

		if (response == '1')
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

		Utils::Pause();
	}


}

//commands to select project and add a time allocation to a subtask
void MenuSystem::CommmandAddTimeAllocation()
{
	Task * temp = GetTaskSelectionFromUser(GetProjectSelectionFromUser());
	if (temp != nullptr)
	{
		CommandAddTA(temp);
	}
}

void CommandAddTA(Task *pT)
{
	RuntimeMenu::DisplayTitle();

	std::cout << "What kind of Time Allocation would you like to add? \n";
	std::cout << "Warning: This cant be undone, enter # to return to the main menu if you require.\n";
	std::cout << "1. Meeting\n";
	std::cout << "2. Work Done\n";
	std::cout << "3. Bug Fix\n";
	std::cout << "4. Research\n";

	char input = '0';
	bool success = false;
	while (!success)
	{
		std::cin >> input;

		switch (input)
		{
		case '1':
			success = true;
			//meeting
			Utils::CreateMeeting(pT);
			break;
		case '2':
			success = true;
			//work done
			Utils::CreateWorkDone(pT);
			break;
		case '3':
			success = true;
			//bug fix
			Utils::CreateBugFix(pT);
			break;
		case '4':
			success = true;
			//research
			Utils::CreateResearch(pT);
			break;
		case '#':
			return;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}

	//write to file
	//only if data was added
	if (input != '#')
	{
		DataCzar::Current->SaveToFile();
		std::cout << "Time Allocation added. Press any key to continue";
		Utils::Pause();
	}
}

//commands to select a project/task and edit TA
void MenuSystem::CommandEditTimeAllocation()
{
	std::shared_ptr<TimeAllocation> &temp = GetTimeAllocationSelectionFromUser(GetTaskSelectionFromUser(GetProjectSelectionFromUser()));

	if (temp != nullptr)
	{
		temp->EditClassFromUser();
		//save changes to file
		DataCzar::Current->SaveToFile();

		std::cout << "Time Allocation edited and saved. Press any key to continue...";
		Utils::Pause();
	}
}

//commands to add new project
void MenuSystem::CommandAddProject()
{
	RuntimeMenu::DisplayTitle();

	Project p;

	std::cout << "Please enter the new projects name: \n";
	std::string temp;
	std::getline(std::cin >> std::ws, temp);
	p.SetName(temp);
	std::cout << "Please enter the new projects descriptions:\n";
	std::getline(std::cin >> std::ws, temp);
	p.SetDesc(temp);
	std::cout << "When does the project start? DD/MM/YYYY HH:MM\n";
	std::getline(std::cin >> std::ws, temp);
	p.SetStart(temp);
	std::cout << "When does the project end? DD/MM/YYYY HH:MM\n";
	std::getline(std::cin >> std::ws, temp);
	p.SetDeadline(temp);

	DataCzar::Current->GetProjects().push_back(p);
	DataCzar::Current->SaveToFile();
	std::cout << "Project added. Please press enter...\n";
	Utils::Pause();
}

//commmands to add new task
void MenuSystem::CommandAddTask()
{
	auto * projectToEdit = GetProjectSelectionFromUser();

	if (projectToEdit == nullptr)
	{
		return;
	}

	RuntimeMenu::DisplayTitle();

	Task t;
	std::cout << "Please enter the new tasks name: \n";
	std::string temp;
	std::getline(std::cin >> std::ws, temp);
	t.SetName(temp);
	std::cout << "Please enter the new tasks descriptions:\n";
	std::getline(std::cin >> std::ws, temp);
	t.SetDesc(temp);
	std::cout << "When does the task start? DD/MM/YYYY HH:MM\n";
	std::getline(std::cin >> std::ws, temp);
	t.SetStart(temp);
	std::cout << "When does the task end? DD/MM/YYYY HH:MM\n";
	std::getline(std::cin >> std::ws, temp);
	t.SetDeadline(temp);

	projectToEdit->GetTasks().push_back(t);
	DataCzar::Current->SaveToFile();
	std::cout << "Task added. Please press enter...\n";
	Utils::Pause();
}


//helper functions
Project * GetProjectSelectionFromUser()
{
	RuntimeMenu::DisplayTitle();

	std::cout << "Here are the currently loaded projects:\n";

	for (Project &p : DataCzar::Current->GetProjects())
	{
		std::cout << p.GetName() << "\n";
	}

	std::cout << "Enter the name of the project you wish to edit:\n";
	std::cout << "(Enter # to exit to main menu)\n";

	std::string input;
	bool success = false;
	Project * projectToEdit = nullptr;

	while (!success)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin >> std::ws, input);

		if (input == "#")
		{
			return nullptr;
		}

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

	return projectToEdit;
}

Task * GetTaskSelectionFromUser(Project * projectToEdit)
{
	if (projectToEdit == nullptr)
	{
		return nullptr;
	}
	RuntimeMenu::DisplayTitle();

	std::cout << "Here are the currently loaded tasks:\n";

	for (Task &t : projectToEdit->GetTasks())
	{
		std::cout << t.GetName() << "\n";
	}

	std::cout << "Enter the name of the task you wish to edit:\n";
	std::cout << "(Enter # to exit to main menu)\n";

	Task * taskToEdit = nullptr;
	std::string input;
	bool success = false;
	while (!success)
	{
		std::getline(std::cin >> std::ws, input);

		if (input == "#")
		{
			return nullptr;
		}

		for (Task &t : projectToEdit->GetTasks())
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

	return taskToEdit;
}

std::shared_ptr<TimeAllocation> GetTimeAllocationSelectionFromUser(Task * taskToEdit)
{
	if (taskToEdit == nullptr)
	{
		return nullptr;
	}
	RuntimeMenu::DisplayTitle();
	std::cout << "Here are the currently loaded Time Allocations:\n";

	int counter = 0;

	for (auto &ta : taskToEdit->GetTAs())
	{
		std::cout << ++counter << ". " << ta->GetDetails() << "\n";
	}

	std::cout << "Enter the number of the Time Allocation you wish to edit: \n";
	std::cout << "(Enter # to exit to main menu)\n";

	std::shared_ptr<TimeAllocation> taToEdit = nullptr;
	std::string input;
	bool success = false;

	while (!success)
	{
		std::getline(std::cin >> std::ws, input);

		if (input == "#")
		{
			return nullptr;
		}

		counter = 0;

		for (auto &ta : taskToEdit->GetTAs())
		{
			if (std::to_string(++counter) == input)
			{
				taToEdit = ta;
				success = true;
			}
		}
		if (!success)
		{
			std::cout << "Input not recognised, try again.\n";
		}
	}

	return taToEdit;
}
