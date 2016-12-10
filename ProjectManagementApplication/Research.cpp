#include "Research.h"
Research::Research(){}
Research::~Research(){}

const std::string Research::GetDetails() const
{
	std::stringstream temp;
	temp << spacer << "Research: " << start_.getFormatted() << " - " << end_.getFormatted() << " Topic: " << details_;
	return temp.str();
}

void Research::SetUpNewClassFromUser()
{
	std::cout << "Please enter a description of the research:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, details_);
	std::cout << "When was the research started? dd/mm/yyyy hh:mm\n";
	std::string temp;
	std::getline(std::cin, temp);
	DateTime d(temp);
	start_ = d;
	std::cout << "When was the research ended? dd/mm/yyyy hh:mm\n";
	std::getline(std::cin, temp);
	DateTime d2(temp);
	end_ = d2;
}