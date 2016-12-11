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
	std::cout << "Please enter the work that was done:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, desc_);
	std::cout << "When was the work started? dd/mm/yyyy hh:mm\n";
	std::string temp;
	std::getline(std::cin, temp);
	DateTime d(temp);
	start_ = d;
	std::cout << "When was the work ended? dd/mm/yyyy hh:mm\n";
	std::getline(std::cin, temp);
	DateTime d2(temp);
	end_ = d2;
	std::cout << "Please enter the ID of any Persons assigned to this, separated by commas (no spaces):\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, temp);
	PopulatePersonIDs(temp);
}
