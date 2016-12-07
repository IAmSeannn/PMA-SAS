#include <iostream>
#include "DataCzar.h"
#include "DataDisplayer.h"
#include "RuntimeMenu.h"

void CommandLoadXMLFIle(DataCzar &Data);
void CommandLoadMainMenu(DataCzar &Data);
void CommandLoadDisplayData(DataCzar &Data);

void CommandLoadXMLFIle(DataCzar &Data)
{
	RuntimeMenu::DisplayLoadXMLMenu();
	std::string temp;
	bool success = false;
	while (!success)
	{
		std::cin >> temp;
		tinyxml2::XMLError error = Data.SetUp(temp);
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
	CommandLoadMainMenu(Data);
}

void CommandLoadDisplayData(DataCzar &Data)
{

}

void CommandLoadMainMenu(DataCzar &Data)
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
			CommandLoadXMLFIle(Data);
			break;
		case 2:
			responseSuccess = true;
			//display data
			CommandLoadDisplayData(Data);
			break;
		case 3:
			responseSuccess = true;
			//sort data, then display
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
	
	DataCzar Data;

	CommandLoadMainMenu(Data);
	
	std::cin.get();
	std::cin.get();
}