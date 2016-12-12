#include "DataCzar.h"
#include "MenuSystem.h"
#include "Utils.h"

void LoadInitialFile()
{
	RuntimeMenu::DisplayTitle();
	std::cout << "No arguments provided, or the data was not loaded sucessfully.\n";
	std::cout << "Please input the path of a valid XML file.\n";

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
	Utils::Pause();
}

int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);

	//DataCzar Data("testing.xml");
	//DataDisplayer::PrintTest(Data);

	//initialise static dataczar
	std::shared_ptr<DataCzar> d(new DataCzar);
	DataCzar::Current = d;

	//check for args and try load
	if (argc > 1)
	{
		tinyxml2::XMLError error = DataCzar::Current->SetUp(argv[1]);
		if (error == tinyxml2::XML_SUCCESS)
		{
			RuntimeMenu::DisplayLoadXMLMenu();
			std::cout << "Data loaded successfully. Press any key to continue...";
			Utils::Pause();
		}
		else
		{
			LoadInitialFile();
		}
	}
	else
	{
		LoadInitialFile();
	}

	MenuSystem::CommandLoadMainMenu();
}