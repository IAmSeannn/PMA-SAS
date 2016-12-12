#include "Meeting.h"
Meeting::Meeting(){}
Meeting::~Meeting(){}

const std::string Meeting::GetDetails() const
{
	std::stringstream temp;
	temp << MagicStr::SpaceTA << "Meeting:\n";
	temp << MagicStr::SpaceTA << " TimeSpan: " << start_.getFormatted() << " - " << end_.getFormatted() << "\n";
	temp << MagicStr::SpaceTA << " Attendees: " << attendees_ << "\n";
	temp << MagicStr::SpaceTA << " Persons Involved: " << GetPersonNamesFormatted();
	return temp.str();
}

void Meeting::SetUpNewClassFromUser()
{
	SetupNewAttendeesFromUser();
	SetupNewStartTime();
	SetupNewEndTime();
	SetupNewPersonsInvolved();
}

void Meeting::EditClassFromUser()
{
	std::cout << "What would you like to edit?\n";
	std::cout << "(Enter # to return to main menu)\n";
	std::cout << "1. Start DateTime\n";
	std::cout << "2. End DateTime\n";
	std::cout << "3. Add Person Involved\n";
	std::cout << "4. Edit Attendees\n";

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
			SetupNewAttendeesFromUser();
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

void Meeting::SetupNewAttendeesFromUser()
{
	std::cout << "Please enter who will be attending:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, attendees_);
}
