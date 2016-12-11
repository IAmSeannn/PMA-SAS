#include "Research.h"
Research::Research(){}
Research::~Research(){}

const std::string Research::GetDetails() const
{
	std::stringstream temp;
	temp << MagicStr::SpaceTA << "Research:\n";
	temp << MagicStr::SpaceTA << " TimeSpan: " << start_.getFormatted() << " - " << end_.getFormatted() << "\n";
	temp << MagicStr::SpaceTA << " Topic: " << details_ << "\n";
	temp << MagicStr::SpaceTA << " Persons Involved: " << GetPersonNamesFormatted();
	return temp.str();
}

void Research::SetUpNewClassFromUser()
{
	SetupNewResearchDetailsFromUser();
	SetupNewStartTime();
	SetupNewEndTime();
	SetupNewPersonsInvolved();
}

void Research::EditClassFromUser()
{
	std::cout << "What would you like to edit?\n";
	std::cout << "(Enter # to return to main menu)\n";
	std::cout << "1. Start DateTime\n";
	std::cout << "2. End DateTime\n";
	std::cout << "3. Add Person Involved\n";
	std::cout << "4. Edit Research Details\n";

	char input;
	bool success = false;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
			SetupNewResearchDetailsFromUser();
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

void Research::SetupNewResearchDetailsFromUser()
{
	std::cout << "Please enter a description of the research:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, details_);
}