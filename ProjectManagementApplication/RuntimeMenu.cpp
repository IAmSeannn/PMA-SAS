#include "RuntimeMenu.h"

void DisplayTitle()
{
	system("CLS");
	std::cout << "------------------------------------------\n";
	std::cout << "   Super Project Management Program 1.0\n";
	std::cout << "------------------------------------------\n";
}

RuntimeMenu::RuntimeMenu()
{
}


RuntimeMenu::~RuntimeMenu()
{
}

void RuntimeMenu::DisplayMainMenu()
{
	DisplayTitle();
	std::cout << "----------\n";
	std::cout << "Main Menu: \n";
	std::cout << "----------\n";

	std::cout << "Select from the following actions below by entering the corrisponding number: \n";
	std::cout << " 1. Load XML File\n";
	std::cout << " 2. Display Loaded Data\n";
	std::cout << " 3. Sort Data, Then Display\n";
	std::cout << " 4. Edit Data\n";
	std::cout << " 5. Quit\n";
}

void RuntimeMenu::DisplayLoadXMLMenu()
{
	DisplayTitle();
	std::cout << "--------------\n";
	std::cout << "Load XML File:\n";
	std::cout << "--------------\n";

	std::cout << "Please input the path of the file you wish to load:\n";
}

void RuntimeMenu::DisplayData()
{

}
