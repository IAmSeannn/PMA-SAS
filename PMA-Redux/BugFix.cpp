#include "BugFix.h"



BugFix::BugFix()
{
}


BugFix::~BugFix()
{
}

const std::string BugFix::GetDetails() const
{
	std::stringstream temp;
	temp << MagicStr::SpaceTA << "Bug Fix:\n";
	temp << MagicStr::SpaceTA << " TimeSpan: " << start_.getFormatted() << " - " << end_.getFormatted() << "\n";
	temp << MagicStr::SpaceTA << " ID: " << id_ << " Description: " << desc_ << "\n";
	temp << MagicStr::SpaceTA << " Persons Involved: " << GetPersonNamesFormatted();
	return temp.str();
}

void BugFix::SetUpNewClassFromUser()
{
	SetupNewBugIDAndDetailsFromUser();
	SetupNewStartTime();
	SetupNewEndTime();
	SetupNewPersonsInvolved();
}

void BugFix::EditClassFromUser()
{
	std::cout << "What would you like to edit?\n";
	std::cout << "(Enter # to return to main menu)\n";
	std::cout << "1. Start DateTime\n";
	std::cout << "2. End DateTime\n";
	std::cout << "3. Add Person Involved\n";
	std::cout << "4. Edit Bug Fix ID and Details\n";

	char input;
	bool success = false;
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
			SetupNewBugIDAndDetailsFromUser();
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

void BugFix::SetupNewBugIDAndDetailsFromUser()
{
	std::cout << "Please enter a description of the Bug Fix:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, desc_);
	std::cout << "Please enter the bug ID:\n";
	std::cin >> id_;
}