#include "RuntimeMenu.h"

RuntimeMenu::RuntimeMenu() {}
RuntimeMenu::~RuntimeMenu() {}

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

void RuntimeMenu::DisplayTitle()
{
	system("CLS");
	std::cout << "------------------------------------------\n";
	std::cout << "   Super Project Management Program 1.0\n";
	std::cout << "------------------------------------------\n";
}

std::string RuntimeMenu::TurnIntoSubtitle(std::string s, std::string spacer)
{
	std::stringstream stream;
	//first line
	stream << spacer;
	for (int i = 0; i < s.length(); i++)
	{
		stream << "-";
	}
	stream << "\n";

	stream << spacer << s << "\n";
	stream << spacer;
	//second line
	for (int i = 0; i < s.length(); i++)
	{
		stream << "-";
	}
	stream << "\n";

	return stream.str();
}

std::string RuntimeMenu::GetTimeSpentString(int minutesSpent, std::string spacer)
{
	int minute, hour, day, month, year;

	year = (minutesSpent / 518400);
	minutesSpent = minutesSpent % 518400;
	month = minutesSpent / 43200;
	minutesSpent = minutesSpent % 43200;
	day = minutesSpent / 1440;
	minutesSpent = minutesSpent % 1440;
	hour = minutesSpent / 60;
	minutesSpent = minutesSpent % 60;
	minute = minutesSpent;

	std::stringstream temp;
	temp << spacer << "Time Spent: ";
	if (year > 0)
	{
		temp << year << " years ";
	}
	if (month > 0)
	{
		temp << month << " months ";
	}
	if (day > 0)
	{
		temp << day << " days ";
	}
	if (hour > 0)
	{
		temp << hour << " hours ";
	}
	if (minute > 0)
	{
		temp << minute << " minutes";
	}
	temp << "\n";
	return temp.str();
}
