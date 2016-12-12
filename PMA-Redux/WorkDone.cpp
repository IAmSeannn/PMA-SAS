#include "WorkDone.h"
WorkDone::WorkDone(){}
WorkDone::~WorkDone(){}




const std::string WorkDone::GetDetails() const
{
	std::stringstream temp;
	temp << MagicStr::SpaceTA << "Work Done:\n";
	temp << MagicStr::SpaceTA << " TimeSpan: " << start_.getFormatted() << " - " << end_.getFormatted() << "\n";
	temp << MagicStr::SpaceTA << " Description: " << desc_ << "\n";
	temp << MagicStr::SpaceTA << " Persons Involved: " << GetPersonNamesFormatted();
	return temp.str();
}

void WorkDone::SetUpNewClassFromUser()
{
	SetupNewWorkDoneFromUser();
	SetupNewStartTime();
	SetupNewEndTime();
	SetupNewPersonsInvolved();
}

void WorkDone::EditClassFromUser()
{
	std::cout << "What would you like to edit?\n";
	std::cout << "(Enter # to return to main menu)\n";
	std::cout << "1. Start DateTime\n";
	std::cout << "2. End DateTime\n";
	std::cout << "3. Add Person Involved\n";
	std::cout << "4. Edit Work Done\n";

	//ERROR LOCATION, UNSURE WHY

	char input;
	bool success = false;
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//std::cin >> std::ws >> input;
	std::cin >> input;
	while (!success)
	{
		switch (input)
		{
		case '1':
			SetupNewStartTime();
			success = true;
			break;
		case '2':
			SetupNewEndTime();
			success = true;
			break;
		case '3':
			SetupNewPersonsInvolved();
			success = true;
			break;
		case '4':
			SetupNewWorkDoneFromUser();
			success = true;
			break;
		case '#':
			return;
			break;
		default:
			std::cout << "Command not recognised, please try again.\n";
			break;
		}
	}
}

void WorkDone::SetupNewWorkDoneFromUser()
{
	std::cout << "Please enter the work that was done:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, desc_);
}
