#include "WorkDone.h"
WorkDone::WorkDone(){}
WorkDone::~WorkDone(){}

const std::string WorkDone::GetDetails() const
{
	std::stringstream temp;
	temp << spacer << "Work Done: " << start_.getFormatted() << " - " << end_.getFormatted() << " Description: " << desc_;
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
}
