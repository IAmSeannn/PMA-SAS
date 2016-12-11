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
	std::cout << "Please enter the names of who will be attending, in one line, separated by commas:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, attendees_);
	std::cout << "When does the meeting start? dd/mm/yyyy hh:mm\n";
	std::string temp;
	std::getline(std::cin, temp);
	DateTime d(temp);
	start_ = d;
	std::cout << "When does the meeting end? dd/mm/yyyy hh:mm\n";
	std::getline(std::cin, temp);
	DateTime d2(temp);
	end_ = d2;
}
